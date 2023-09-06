#include "mytree.h"
#include "public.h"
#include <QFileDialog>
#include "QMessageBox"
#include "QInputDialog"
#include<QDebug>
#include"mainwindow.h"
#include<QTimer>
void myTree::init_public(){
    connect(&model,&QFileSystemModel::directoryLoaded,this,[=](QString path){
        qDebug()<<"dirload-signal:"<<path;
    });

    setModel(&model);//设置模型
    reSetBlank();
    connect(this,&myTree::doubleClicked,this,&myTree::doubleClickItem);//双击事件
}

myTree::myTree():QTreeView(){
    init_public();
}

myTree::myTree(QWidget *parent):QTreeView(parent){
    dialogcontext=parent;//设置对话弹出的上下文
    init_public();
}

void myTree::reSetBlank()
{
    model.setRootPath("");//如果不初始化，第一次加载直接加载磁盘会因为加载磁盘线程未加载完，又没有可用信号而出现bug。
    reset();
    goalpath=goalpath_father=nullptr;

    //很短的一段时间后(10ms)，清除界面，但是不能完全不延迟
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,[=]{
        delete timer;
        ready("");
    });
    timer->start(outtime);

    for(int i=1;i<=3;i++){
        setColumnHidden(i,true);//隐藏不需要的列
    }

}
//结合loaddir和directoryLoaded信号使用,从path中筛出goalpath
void myTree::ready(QString path){
    //此时model的根目录准备完毕，可以使用了
    QModelIndex root=model.index(path);
    setRootIndex(root);//设置给treeview
    qDebug()<<root;
    int rowcount=model.rowCount(root);//获取目录数量
    qDebug()<<"rowcount:"<<rowcount;

    for(int i=0;i<rowcount;i++){
        QModelIndex now=model.index(i,0,root);//逐一扫描
//        qDebug()<<now;
        if(model.filePath(now)!=goalpath){
            setRowHidden(i,root,true);//隐藏该行
        }
    }
}

//等于disconnect+ready
void myTree::ready_pre(QString path){
    qDebug()<<"stop listen signal:"<<goalpath_father;
    //只要接收到信号，不管是不是需要的根目录，都视为不会再收到需要的信号了。
    disconnect(&model,&QFileSystemModel::directoryLoaded,this,&myTree::ready_pre);//停止检测directoryLoaded信号
    if(!absolutePathEquals(goalpath_father,path)) return;//非需要的目录，不刷新
    ready(path);
}

//通过文件选择窗口打开文件夹
void myTree::loaddir(){
    QString path=QFileDialog::getExistingDirectory();
    if(path==""||path==nullptr)return;

    reset();

    QString rt_now=model.rootPath();//model现在的根目录
    QString rt_new=path+"/../";//path的上级，model新的根目录
    toAbsolutePath(rt_now);
    toAbsolutePath(rt_new);

    if(rt_new=="/../")rt_new="/";//Linux根目录无法处理
    if(rt_new==path){//当上级目录跟自身一样(或Linux路径为/)，说明是硬盘，此时路径设置为空字符串，会被识别为"此电脑"
        rt_new="";
        qDebug()<<"盘:"<<rt_new;
    }
    qDebug()<<path<<":"<<rt_now<<" -> "<<rt_new;

    goalpath=path;//设置全局变量：目标目录
    goalpath_father=rt_new;//设置全局变量：根目录，目标的上一级
    connect(&model,&QFileSystemModel::directoryLoaded,this,&myTree::ready_pre);//检测directoryLoaded加载完成，取消连接，刷新界面

    if(absolutePathEquals(rt_now,rt_new)){//此时不会产生变动信号directoryLoaded，手动调用。
        qDebug()<<"load:rt_same";
        disconnect(&model,&QFileSystemModel::directoryLoaded,this,&myTree::ready_pre);//停止检测根目录变动
        ready(rt_now);
    }
    else{
        qDebug()<<"load:rt_nosame";
        model.setRootPath(rt_new);//此时改变model根目录，完成后会产生directoryLoaded信号
        ready(rt_new);//防止没有directoryloaded信号，强制刷新一次，但是不停止监听
    }
}

//添加文件
void myTree::addfile(QModelIndex index){
    if(!model.isDir(index)) return;//不是文件夹

    bool ok;
    QString name=QInputDialog::getText(dialogcontext,"新建文件","请输入文件名",QLineEdit::Normal,"新建文件.cpp",&ok);
    if(name==nullptr) return;
    if(name==""){
        qDebug()<<"名称为空";
        QMessageBox::warning(dialogcontext,"提示","名称不能为空");
        return;
    }
    if(!isValidFileName(name,dialogcontext))return;//判断名称是否合法

    name=model.filePath(index)+"/"+name;
    QFile file(name);
    if(file.exists()){
        qDebug()<<"存在同名文件";
        QMessageBox::warning(dialogcontext,"提示","存在同名文件");
        return;
    }
    if(!file.open(QIODevice::WriteOnly)){
        qDebug()<<"创建文件失败";
        QMessageBox::warning(dialogcontext,"提示","创建文件失败");
        return;
    }
//    sortByColumn(0,Qt::SortOrder::AscendingOrder);
//    file.close();
//    sortChildren(0,Qt::SortOrder::AscendingOrder);
}

//添加文件夹
void myTree::adddir(QModelIndex index){
    if(!model.isDir(index)) return;//不是文件夹
    qDebug()<<"ok1";
    bool ok;
    QString name=QInputDialog::getText(dialogcontext,"新建文件夹","请输入文件夹名称",QLineEdit::Normal,"新建文件夹",&ok);
    if(name==nullptr) return;//取消
    if(name==""){//无输入
        qDebug()<<"名称为空";
        QMessageBox::warning(dialogcontext,"提示","名称不能为空");
        return;
    }
    if(!isValidFileName(name,dialogcontext))return;//判断名称是否合法

    QModelIndex newdir=model.mkdir(index,name);//创建文件夹
    if(newdir.isValid()){
        qDebug()<<"创建文件夹成功";
    }
    else{
        qDebug()<<"创建文件夹失败";
        QMessageBox::warning(dialogcontext,"提示","创建文件夹失败");
    }
//    sortByColumn(0,Qt::SortOrder::AscendingOrder);
}

//删除文件(夹)
void myTree::del(QModelIndex index){
    QString path=model.filePath(index);

    //禁止操控硬盘
    if(isDisk(path)){
        QMessageBox::warning(dialogcontext,"警告！","禁止操控硬盘!");
        return;
    }


    //删除无法恢复，提示两次
    int result=QMessageBox::question(dialogcontext,"注意!","确定要删除吗？\n"+path);
    if(result==QMessageBox::No)return;
    result=QMessageBox::question(dialogcontext,"注意!",path+"\n删除后无法恢复，请再次确认");
    if(result==QMessageBox::No)return;

    if(model.isDir(index)){
        QDir dir(path);
        if(dir.removeRecursively()){
            qDebug()<<"文件夹删除成功";
            QMessageBox::warning(dialogcontext,"提示","文件夹删除成功!");
            return;
        }
        else{
            qDebug()<<"文件夹删除失败";
            QMessageBox::warning(dialogcontext,"提示","文件夹删除失败");
            return;
        }
    }
    else{
        if(model.remove(index)){
            qDebug()<<"文件删除成功";
            QMessageBox::warning(dialogcontext,"提示","文件删除成功!");
            return;
        }
        else{
            qDebug()<<"文件删除失败";
            QMessageBox::warning(dialogcontext,"提示","文件删除失败");
            return;
        }
    }
}

//重命名
void myTree::rename(QModelIndex index){

    //禁止操控硬盘
    if(isDisk(model.filePath(index))){
        QMessageBox::warning(dialogcontext,"警告！","禁止操控硬盘!");
        return;
    }

    bool ok;
    QString newname=QInputDialog::getText(dialogcontext,"重命名","请输入新名称",QLineEdit::Normal,model.fileName(index),&ok);
    if(newname==nullptr) return;//取消
    if(newname==""){
        qDebug()<<"名称为空";
        QMessageBox::warning(dialogcontext,"提示","名称不能为空");
        return;
    }
    if(!isValidFileName(newname,dialogcontext))return;

    //重命名要全路径,用相对路径../过不了
    QString path=model.filePath(index);
    QFileInfo info=model.fileInfo(index);
    QString newpath=info.absolutePath()+"/"+newname;
    if(!info.isDir()){
        QFile file(path);
        if(!file.rename(newpath)){
            qDebug()<<"文件重命名失败";
            QMessageBox::warning(dialogcontext,"提示","文件重命名失败");
            return;
        }
    }
    else{
        QDir dir(path);
        if(!dir.rename(path,newpath)){
            qDebug()<<"文件夹重命名失败";
            QMessageBox::warning(dialogcontext,"提示","文件夹重命名失败");
            return;
        }
    }
//    sortByColumn(0,Qt::SortOrder::AscendingOrder);
//    if(parent()!=nullptr){
//        parent()->sortChildren(0,Qt::SortOrder::AscendingOrder);
//    }
}

//双击事件
void myTree::doubleClickItem(const QModelIndex &index){
    qDebug()<<"clicked:"<<index<<"-"<<index.parent();
    if(model.isDir(index))return;
    mainwindow->file_open(model.filePath(index));
}

//右键菜单，接收customContextMenuRequested信号
void myTree::contextMenuEvent(QContextMenuEvent *event){
    qDebug()<<"rightclick";
    QModelIndex clickedindex=indexAt(event->pos());//获取点击位置的Item
    if(!clickedindex.isValid()){//点击空白位置（无效）
        return;
    }
    else{
        // 创建菜单
        QMenu *menu = new QMenu(this);

        // 添加菜单项
        QAction *addfile = new QAction("新建文件", menu);
        connect(addfile,&QAction::triggered,this,[=](bool checked){
            this->addfile(clickedindex);
        });
        QAction *adddir = new QAction("新建文件夹", menu);
        connect(adddir,&QAction::triggered,this,[=](bool checked){
            this->adddir(clickedindex);
        });
        QAction *del=new QAction("删除",menu);
        connect(del,&QAction::triggered,this,[=](bool checked){
            this->del(clickedindex);
        });
        QAction *rename=new QAction("重命名",menu);
        connect(rename,&QAction::triggered,this,[=](bool checked){
            this->rename(clickedindex);
        });

        // 将菜单关联到当前事件
        if(model.isDir(clickedindex)){//是否文件夹
            menu->addAction(addfile);
            menu->addAction(adddir);
        }
        menu->addAction(del);
        menu->addAction(rename);

        // 显示菜单
        menu->exec(event->globalPos());//在当前（全局）位置显示菜单
    }
}
//#include "myTree.h"
//#include "myItem.h"
//#include "mainwindow.h"
//#include <QFileDialog>

//myTree::myTree(QWidget *parent):QTreeWidget(parent){
//    dialogcontext=parent;
//    setHeaderHidden(true);

//    //当接受itemExpanded信号时,所有儿子被显示，需要调用儿子的completeGrandsons
//    connect(this,&QTreeWidget::itemExpanded,this,&myTree::showSons);
//    connect(this,&QTreeWidget::itemDoubleClicked,this,&myTree::doubleClickItem);
//}

////通过文件选择窗口打开文件
//void myTree::loadfile(){
//    clear();
//    QString path=QFileDialog::getOpenFileName();
//    if(path=="")return;
//    myItem *itm=new myItem(this);
//    itm->initInfo(path);//顶层结点信息
//    itm->initSons(path);//添加第二层结点
//    completeGrandsons(itm);//顶层结点默认显示,补充孙子信息
//    root=path;
//}

////通过文件选择窗口打开文件夹
//void myTree::loaddir(){
//    clear();
//    QString path=QFileDialog::getExistingDirectory();
//    if(path=="")return;
//    myItem *itm=new myItem(this);
//    itm->initInfo(path);//同上loadfile函数
//    itm->initSons(path);
//    completeGrandsons(itm);
//    root=path;
//}

////删除文件(夹)，移除结点
//bool myTree::del(QTreeWidgetItem *item){
//    myItem* item2=dynamic_cast<myItem *>(item);
//    bool ok=item2->del(dialogcontext);
//    if(ok){
//        delete item;
//    }
//    return ok;
//}

////设置对话框显示的上下文
//void myTree::setDialogContext(QWidget* context){
//    dialogcontext=context;
//}

////重新显示
//void myTree::refresh(){
//    clear();
//    if(root==nullptr)return;
//    myItem *itm=new myItem(this);
//    itm->initInfo(root);
//    itm->initSons(root);
//}

////双击事件
//void myTree::doubleClickItem(QTreeWidgetItem *item, int column){
//    myItem *item2=dynamic_cast<myItem *>(item);
//    if(item2->type==1)return;//文件夹，由框架自动处理
//    mainwindow->file_open(item2->getPath());
//}

////当结点被展示时，补全其孙子结点信息
////(此时儿子结点还没有被显示，但如果接下来展开结点就会显示儿子结点，需要提前准备孙子结点信息)
//void myTree::completeGrandsons(QTreeWidgetItem *item){
//    int count=item->childCount();
//    for(int i=0;i<count;i++){
//        myItem *son2=dynamic_cast<myItem *>(item->child(i));
//        if(son2->showed_ever) continue;
//        son2->showed_ever=true;
//        son2->initSons(son2->getPath());
//    }
//}

////当接受itemExpanded信号时,所有儿子被显示，需要调用儿子的completeGrandsons
//void myTree::showSons(QTreeWidgetItem *item){
//    int count=item->childCount();
//    for(int i=0;i<count;i++){
//        completeGrandsons(item->child(i));
//    }
//}

////右键菜单
////当右键树形控件时，其自动发出一个QContextMenuEvent *event，重写这个contextMenuEvent函数来接收、处理
//void myTree::contextMenuEvent(QContextMenuEvent *event) {

//    QTreeWidgetItem *clickedItem=itemAt(event->pos());//获取点击位置的Item
//    myItem *clickedItem2=dynamic_cast<myItem *>(clickedItem);

//    if(clickedItem==nullptr){//空白位置

//    }
//    else{
//        // 创建菜单
//        QMenu *menu = new QMenu(this);

//        // 添加菜单项
//        QAction *addfile = new QAction("新建文件", menu);
//        connect(addfile,&QAction::triggered,this,[=](bool checked){
//            clickedItem2->addfile(dialogcontext);
//        });
//        QAction *adddir = new QAction("新建文件夹", menu);
//        connect(adddir,&QAction::triggered,this,[=](bool checked){
//            clickedItem2->adddir(dialogcontext);
//        });
//        QAction *del=new QAction("删除",menu);
//        connect(del,&QAction::triggered,this,[=](bool checked){
//            this->del(clickedItem);
//        });
//        QAction *rename=new QAction("重命名",menu);
//        connect(rename,&QAction::triggered,this,[=](bool checked){
//            clickedItem2->rename(dialogcontext);
//        });

//        // 将菜单关联到当前事件
//        if(clickedItem2->type==1){//文件夹
//            menu->addAction(addfile);
//            menu->addAction(adddir);
//        }
//        menu->addAction(del);
//        menu->addAction(rename);

//        // 显示菜单
//        menu->exec(event->globalPos());//在当前（全局）位置显示菜单
//    }

//}
