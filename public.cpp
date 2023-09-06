#include "public.h"
#include <QMessageBox>
#include <QFileInfo>
#include<QDebug>
//公用函数

//str保存到path
bool saveString(QString str,QString path){
    QFile file(path);
    QTextStream fout(&file);
    if(file.open(QIODevice::WriteOnly)){
        file.write(str.toUtf8());
    }
    else{
        qDebug()<<"public-save:文件只写打开失败";
        return false;
    }
    return true;
}

//打开文件窗口，选择文件位置存储QString
bool saveStringAs(QString str,QWidget* dialogcontext){
    QString path=QFileDialog::getSaveFileName(dialogcontext,"选择保存位置");
    if(path==nullptr)return false;
    saveString(str,path);
}

//判断字符串是否为合法的路径
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

//绝对路径
void toAbsolutePath(QString &path){
    QFileInfo info(path);
    if(info.exists()) path=info.absoluteFilePath();
    //说明：linux下调用绝对路径多余一个/符号
}
bool absolutePathEquals(QString a,QString b){
    if(a==b)return true;//windows，Linux一般
    if(a==""&&b!=""||a!=""&&b=="")return false;//不能是""和"/"
    //说明：有些情况路径多余一个/符号
    if(a+"/"==b||b+"/"==a)return true;

    return false;
}

//判断是否硬盘
bool isDisk(QString path){
    QString path2=path+"/../";
    toAbsolutePath(path2);
    if(path2==path||path=="/"||path=="//")return true;//Windows 或 Linux
    else return false;
}
