#ifndef MYITEM_H
#define MYITEM_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QString>

class myTree;//声明

//结点类，QTreeWidgetItem子类
class myItem:public QTreeWidgetItem
{
public:
    myItem(myItem* parent);
    myItem(myTree* treeview);

    int type;//0:文件 1:文件夹
    bool showed_ever=false;//是否显示过。用于异步加载文件树
    QString getPath();//路径

    void initInfo(QString path);//根据文件路径设置结点信息
    void initSons(QString path);//添加儿子结点
    bool del(QWidget* dialogcontext);//删除该结点代表的文件
    void addfile(QWidget* dialogcontext);//在当前文件夹下创建一个文件
    void adddir(QWidget* dialogcontext);//在当前文件夹下创建一个文件夹
    void rename(QWidget* dialogcontext);//重命名


private:
    QString path;
    QString name;

};

#endif // MYITEM_H
