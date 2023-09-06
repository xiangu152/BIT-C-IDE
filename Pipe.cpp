#include<QCoreApplication>
#include<QProcess>
#include <QApplication>
#include<QDebug>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<iostream>
#include"Pipe.h"
    void Pipe::setIn(int fd2)
    {
    dup2(this->fd[1],fd2);
}
    void Pipe::setOut(int fd2){
    dup2(this->fd[0],fd2);
    }
    void Pipe::Close(int flag)
    {
    close(this->fd[flag]);
}
    void Pipe::Wirte(int flag, const char* input)
{
    write(this->fd[flag],input,strlen(input));
    }
char* Pipe::Read(int flag)
{
    char* buffer = new char[256]; // 使用动态内存分配创建字符数组
    ssize_t bytesRead;
    bytesRead = read(this->fd[flag], buffer, 256); // 请注意这里的大小
    if (bytesRead < 0)
    {
        // 处理读取错误的情况
        delete[] buffer; // 释放内存
        return nullptr; // 或者返回错误代码
    }
    return buffer;
}

