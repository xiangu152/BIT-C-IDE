#include"process.h"
#include<QCoreApplication>
#include<QProcess>
#include <QApplication>
#include<QDebug>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<iostream>
#include"Pipe.h"
#include <chrono>   // std::chrono::seconds
#include <thread>   // std::this_thread::sleep_for
void process::setLine(const QString &line){
    this->lines=line;
}
void process::serName(const QString &name)
{
    this->name=name;
}
QByteArray process::compile()
{
    QByteArray output;
    QProcess proces;
    QString command = "g++";
//    chdir(this->lines.toStdString().c_str());
    QStringList argument;
    argument<<"-o"<<this->name<<this->lines;
    proces.start(command,argument);
    if (proces.waitForFinished(-1))
    {
        // 读取终端输出
        std::this_thread::sleep_for(std::chrono::seconds(1));
        output = proces.readAllStandardOutput();
        QByteArray error = proces.readAllStandardError();
        if (!error.isEmpty())
        {
            // 创建命令和参数列表
            QString command1 = "gnome-terminal";
            QStringList arguments1;
            arguments1 <<"--disable-factory"<< "--" << "bash" << "-c" << "echo " + QString(error) + " && read";

            // 启动gnome-terminal
            QProcess terminalProcess;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            terminalProcess.start(command1, arguments1);

            // 等待终端窗口关闭
            terminalProcess.setProcessChannelMode(QProcess::SeparateChannels);
            terminalProcess.waitForFinished(-1);
        }
    }
    return output;
}
void process::run()
{
    Pipe pi1;
    Pipe pi2;
    pid_t pid;
    pid = fork();
    if(pid==0)
    {
         // 关闭读取端
        pi2.Close(1);
        pi2.setOut(STDIN_FILENO);
        pi1.Close(0);
        // 将标准输出重定向到管道写入端
        pi1.setIn(STDOUT_FILENO);
        pi1.Close(1); // 关闭写入管道
        execl((this->lines+"/"+this->name).toStdString().c_str(), this->name.toStdString().c_str(), nullptr);
    }
    else {
        pi1.Close(1);
        pi2.Close(0);
        const char* inputText = "123\n";
        pi2.Wirte(1,inputText); // 将数据写入管道

        pi2.Close(1); // 关闭写入管道，以便子进程知道数据已经写完
        // 从管道读取子进程的输出
        char* buffer=pi1.Read(0);
        qDebug() << QString::fromUtf8(buffer);
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            pi1.Close(0);
            int exitStatus = WEXITSTATUS(status);
            qDebug() << "Child process exited with status: " << exitStatus;
        } else if (WIFSIGNALED(status)) {
            pi1.Close(0); // 关闭读取端
            int signalNumber = WTERMSIG(status);
            qDebug() << "Child process terminated with signal: " << signalNumber;
        }
    }
}
void process::format(const QString &line,const QString &name)
{
    chdir(line.split(name)[0].toStdString().c_str());
    QProcess pro;
    QString command = "python3";
    QStringList arguments;
    arguments << "./format.py";

    // 启动进程
    pro.start(command, arguments);

    // 输入字符串
    QString userInput = line;
    qDebug()<<line;
    // 将输入字符串写入进程的标准输入
    pro.write(userInput.toUtf8());
    pro.closeWriteChannel();  // 关闭写通道
    pro.waitForFinished(-1);
    // 读取进程的输出
    QString output = pro.readAllStandardOutput();

    // 打印输出
    qDebug() << "Output from format.py:" << output;
}
void process::mutiple(QList<QString> name_list, QList<QString> path_list)
{
    for(int j=0;j<name_list.length();j++)
    {
        qDebug()<<"name:"<<name_list.at(j);
        qDebug()<<"path:"<<path_list.at(j);
    }
    QProcess pro;
    QString command="g++";
    QStringList argument;
    argument<<"-o"<<path_list[0].split(".")[0];
    qDebug()<<path_list[0].split(".")[0];
    for(int j=0;j<name_list.length();j++)
    {
        argument<<path_list[j];
        qDebug()<<path_list[j];
    }
    pro.start(command,argument);
    if (pro.waitForFinished(-1))
    {
        // 读取终端输出
        std::this_thread::sleep_for(std::chrono::seconds(1));
        QByteArray output = pro.readAllStandardOutput();
        QByteArray error = pro.readAllStandardError();
        if (!error.isEmpty())
        {
            // 创建命令和参数列表
            QString command1 = "gnome-terminal";
            QStringList arguments1;
            arguments1 <<"--disable-factory"<< "--" << "bash" << "-c" << "echo " + QString(error) + " && read";

            // 启动gnome-terminal
            QProcess terminalProcess;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            terminalProcess.start(command1, arguments1);

            // 等待终端窗口关闭
            terminalProcess.setProcessChannelMode(QProcess::SeparateChannels);
            terminalProcess.waitForFinished(-1);
        }
    }
}
