#ifndef MYTREE_NEW_H
#define MYTREE_NEW_H

#include <QTreeView>
#include <QContextMenuEvent>
#include <QMenu>
#include <QFileSystemModel>
#include <QFile>
#include <QFileInfo>

class MainWindow;

class myTree:public QTreeView
{
public:

    QFileSystemModel model;//文件系统模型
    QWidget *dialogcontext;//对话弹出的上下文
    MainWindow *mainwindow;
    void init_public();//初始化
    myTree();
    myTree(QWidget *parent);
    int outtime =10;

    void loaddir();//通过文件选择窗口打开文件夹
    void addfile(QModelIndex index);//添加文件
    void adddir(QModelIndex index);//添加文件夹
    void del(QModelIndex index);//删除文件(夹)
    void rename(QModelIndex index);//重命名
    void reSetBlank();

private slots:
    void doubleClickItem(const QModelIndex &index);//双击事件
    void ready(QString path);//结合loaddir和directoryLoaded信号使用,从path中筛出goalpath
    void ready_pre(QString path);//断开连接+ready

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;//右键菜单

public:
    QString goalpath=nullptr;//切换目录时的目标路径
    QString goalpath_father=nullptr;
};




#endif // MYTREE_NEW_H

//#ifndef MYTREE_H
//#define MYTREE_H

//#include <QWidget>
//#include <QTreeWidget>
//#include <QMenu>
//#include <QContextMenuEvent>

//class myItem;
//class MainWindow;

////自定义QTreeWidget子类
//class myTree:public QTreeWidget
//{
//public:
//    MainWindow *mainwindow;
//    myTree(QWidget *parent = nullptr);

//    void loadfile();//通过文件选择窗口打开文件
//    void loaddir();//通过文件选择窗口打开文件夹
//    bool del(QTreeWidgetItem *item);//删除文件(夹)，移除结点
//    void setDialogContext(QWidget* context);//设置对话框显示的上下文


//private:
//    QString root=nullptr;
//    QWidget* dialogcontext;
//    void refresh();//重新显示

//private slots:
//    void doubleClickItem(QTreeWidgetItem *item, int column);//双击事件
//    //当结点被展示时，补全其孙子结点信息
//    //(此时儿子结点还没有被显示，但如果接下来展开结点就会显示儿子结点，需要提前准备孙子结点信息)
//    void completeGrandsons(QTreeWidgetItem *item);
//    void showSons(QTreeWidgetItem *item);//当接受itemExpanded信号时,所有儿子被显示，需要调用儿子的completeGrandsons

//protected:
//    void contextMenuEvent(QContextMenuEvent *event) override;//设置右键菜单
//};

//#endif // MYTREE_H
