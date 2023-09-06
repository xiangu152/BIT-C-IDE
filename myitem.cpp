

#include <QDir>
#include <QFileInfo>
#include <QIcon>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include "myitem.h"
#include "mytree.h"
#include<QDebug>

myItem::myItem(myItem* parent):QTreeWidgetItem((QTreeWidgetItem *)parent){}
myItem::myItem(myTree* treeview):QTreeWidgetItem((QTreeWidget *)treeview){}

QString icon_file="../IDE/icons/文件.png";
QString icon_dir="../IDE/icons/文件夹.png";

bool isValidFileName(const QString& fileName,QWidget* dialogcontext) {
    if(fileName.length()>256){
        qDebug()<<"文件(夹)名称过长";
        QMessageBox::warning(dialogcontext,"提示","文件(夹)名称过长!");
        return false;
    }

    int chars=9;
    char nochars[20]={'/','\\','*','?','<','>',':','\"','|'};

    for(int i=0;i<chars;i++){
        if(fileName.contains(nochars[i])){
            qDebug()<<"包含非法字符:\'"+(QString)nochars[i]+"\'";
            QMessageBox::warning(dialogcontext,"提示","包含非法字符:\'"+(QString)nochars[i]+"\'");
            return false;
        }
    }
    return true;
}

//路径
QString myItem::getPath(){
    return path;
}

//根据文件路径设置结点信息
void myItem::initInfo(QString path){
    QFileInfo info(path);
    this->path=info.absoluteFilePath();//保存路径
    name=info.fileName();//保存名称
    setText(0,name);//显示

    if(info.isDir()){
        type=1;//文件夹
        setIcon(0,QIcon(icon_dir));
    }
    else{
        type=0;//文件
        setIcon(0,QIcon(icon_file));
    }
}

//添加儿子结点
void myItem::initSons(QString path){
    //添加下一级
    QDir dir(path);
    QStringList sons=dir.entryList(QDir::NoDotAndDotDot|QDir::AllDirs|QDir::Files);//获取全部路径，不包括自身和上级文件夹

    for(const QString &son:sons){
        myItem* itm=new myItem(this);//创建并添加子节点
        itm->initInfo(path+"/"+son);//设置子节点信息
    }
}

//删除该结点代表的文件
bool myItem::del(QWidget* dialogcontext){
    int result=QMessageBox::question(dialogcontext,"注意!","确定要删除吗？\n"+path);
    if(result==QMessageBox::No)return false;
    result=QMessageBox::question(dialogcontext,"注意!",path+"\n删除后无法恢复，请再次确认");
    if(result==QMessageBox::No)return false;

    if(type==0){
        QFile file(path);
        if(file.remove()){
            qDebug()<<"文件删除成功";
            QMessageBox::warning(dialogcontext,"提示","文件删除成功!");
            return true;
        }
        else{
            qDebug()<<"文件删除失败";
            QMessageBox::warning(dialogcontext,"提示","文件删除失败");
            return false;
        }
    }
    else if(type==1){
        QDir dir(path);
        if(dir.removeRecursively()){
            qDebug()<<"文件夹删除成功";
            QMessageBox::warning(dialogcontext,"提示","文件夹删除成功!");
            return true;
        }
        else{
            qDebug()<<"文件夹删除失败";
            QMessageBox::warning(dialogcontext,"提示","文件夹删除失败");
            return false;
        }
    }
}

//在当前文件夹下创建一个文件
void myItem::addfile(QWidget* dialogcontext){
    if(type==0) return;

    bool ok;
    QString name=QInputDialog::getText(dialogcontext,"新建文件","请输入文件名",QLineEdit::Normal,"新建文件.txt",&ok);
    if(name==nullptr) return;
    if(name==""){
        qDebug()<<"名称为空";
        QMessageBox::warning(dialogcontext,"提示","名称不能为空");
        return;
    }
    if(!isValidFileName(name,dialogcontext))return;

    name=path+"/"+name;
    QFile file(name);
    if(file.exists()){
        qDebug()<<"存在同名文件(夹)";
        QMessageBox::warning(dialogcontext,"提示","存在同名文件(夹)");
        return;
    }
    if(!file.open(QIODevice::WriteOnly)){
        qDebug()<<"创建文件失败";
        QMessageBox::warning(dialogcontext,"提示","创建文件失败");
        return;
    }

    myItem* item=new myItem(this);
    item->initInfo(name);

    sortChildren(0,Qt::SortOrder::AscendingOrder);
}

//在当前文件夹下创建一个文件夹
void myItem::adddir(QWidget* dialogcontext){
    if(type==0) return;

    bool ok;
    QString name=QInputDialog::getText(dialogcontext,"新建文件夹","请输入文件夹名称",QLineEdit::Normal,"新建文件夹",&ok);
    if(name==nullptr) return;
    if(name==""){
        qDebug()<<"名称为空";
        QMessageBox::warning(dialogcontext,"提示","名称不能为空");
        return;
    }
    if(!isValidFileName(name,dialogcontext))return;
    name=path+"/"+name;

    QDir dir(name);
    if(dir.exists()){
        qDebug()<<"存在同名文件(夹)";
        QMessageBox::warning(dialogcontext,"提示","存在同名文件(夹)");
        return;
    }
    if(!dir.mkdir(name)){
        qDebug()<<"创建文件夹失败";
        QMessageBox::warning(dialogcontext,"提示","创建文件夹失败");
        return;
    }

    myItem* item=new myItem(this);
    item->initInfo(name);

    sortChildren(0,Qt::SortOrder::AscendingOrder);
}

//重命名
void myItem::rename(QWidget* dialogcontext){
    bool ok;
    QString newname=QInputDialog::getText(dialogcontext,"重命名","请输入新名称",QLineEdit::Normal,this->name,&ok);
    if(newname==nullptr) return;
    if(newname==""){
        qDebug()<<"名称为空";
        return;
    }
    if(!isValidFileName(newname,dialogcontext))return;

    //重命名要全路径,用相对路径../过不了
    QFileInfo* info1=new QFileInfo(path);
    QString newpath=info1->absolutePath()+"/"+newname;
    if(type==0){
        QFile file(path);
        if(!file.rename(newpath)){
            qDebug()<<"文件重命名失败";
            QMessageBox::warning(dialogcontext,"提示","文件重命名失败");
            return;
        }
    }
    else if(type==1){
        QDir dir(path);
        if(!dir.rename(path,newpath)){
            qDebug()<<"文件夹重命名失败";
            QMessageBox::warning(dialogcontext,"提示","文件夹重命名失败");
            return;
        }
    }

    path=newpath;
    name=newname;
    setText(0,name);
    if(parent()!=nullptr){
        parent()->sortChildren(0,Qt::SortOrder::AscendingOrder);
    }
}
