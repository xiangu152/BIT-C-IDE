#ifndef PUBLIC_H
#define PUBLIC_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
//通用函数

//str保存到path
bool saveString(QString str,QString path);

//打开文件窗口，选择文件位置存储QString,第二个参数是对话窗口显示的上下文
bool saveStringAs(QString str,QWidget* dialogcontext);

//判断字符串是否为合法的路径
bool isValidFileName(const QString& fileName,QWidget* dialogcontext);

//绝对路径
void toAbsolutePath(QString &path);
bool absolutePathEquals(QString a,QString b);

//判断是否硬盘
bool isDisk(QString path);
#endif // PUBLIC_H
