#include<QCoreApplication>
#include<QProcess>
#include <QApplication>
#include<QDebug>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<iostream>
#include<QByteArray>
class Pipe{
public:
    Pipe()
    {
        pipe(this->fd);
    }
    void setIn(int fd2);
    void setOut(int fd2);
    void Close(int flag);
    void Wirte(int flag,const char* input);
    char* Read(int flag);
private:
    int fd[2];
};
