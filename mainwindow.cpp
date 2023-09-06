#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QWidgetAction>
#include<QMenu>
#include<QMenuBar>
#include<QtDebug>
#include<QInputDialog>
#include<QMessageBox>
#include"searchform.h"
#include"replaceform.h"
#include<QFontDialog>
#include<QFileDialog>
#include <QTextCodec>
#include"public.h"
#include"codeform.h"
#include"Pipe.h"
#include"process.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->file_widget->mainwindow=this;
//    ui->tabWidget->currentWidget()->getWidget()->searchForm->hide();
//    ui->text_widget->replaceform->hide();
//    Highlighter* highlighter = new Highlighter(ui->text_widget->text_widget->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newTab(QString name,QString path,QString str)
{
    int index=-1;
    for(int i=0;i<ui->tabWidget->count();i++)
    {
        if(path==getWidget(i)->path)
        {
            index=i;
            break;
        }
    }
    if(index!=-1)
        ui->tabWidget->setCurrentIndex(index);
    else
    {
        CodeForm * cf=new CodeForm();
        font.setFamily("Consolas");
        font.setPointSize(12);
        cf->setFont(font);
        cf->setText(str);
        cf->path=path;
        cf->name=name;
        cf->setRunSetting(is_show_IO);
        ui->tabWidget->addTab(cf,name);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    }
}

CodeForm* MainWindow::getCurrentWidget()
{
    return static_cast<CodeForm*>(ui->tabWidget->currentWidget());
}

CodeForm* MainWindow::getWidget(int i)
{
    return static_cast<CodeForm*>(ui->tabWidget->widget(i));
}

void MainWindow::file_open(QString path)
{
    QTextCodec *codec=QTextCodec::codecForName("GB2312");
    char* fileName = codec->fromUnicode(path).data();

    /*********/
    QFileInfo fileInfo = QFileInfo(path);
    QString filename=fileInfo.fileName();
    QString filepath=fileInfo.filePath();
    /********/

    // 使用fopen()打开文件，以二进制模式读取
    FILE* fp = fopen(fileName, "rb");

    if(fp == NULL)
        return; // 打开文件失败，则返回

    // 循环读取文件内容，使用fgets()读取文本行
    char buf[2048];
    QString str = ""; // 用于存储读取的文本内容
    while(1) {
        memset(buf, 0, sizeof(buf)); // 读取前清空buf内容
        fgets(buf, sizeof(buf), fp);
        str+=buf;
        if(feof(fp))
            break; // 如果文件已结束，则结束循环
    }
    fclose(fp);
    // 将读取到的文本内容设置为文本编辑框的显示文本
    newTab(filename,filepath,str);
//    CodeForm * cf=new CodeForm();
//    font.setFamily("Consolas");
//    font.setPointSize(12);
//    cf->setFont(font);
//    cf->setText(str);
//    cf->path=filepath;
//    cf->name=filename;
//    cf->setRunSetting(is_show_IO);
//    ui->tabWidget->addTab(cf,filename);
//    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

void MainWindow::on_action_paste_triggered()
{
    getCurrentWidget()->paste();
}

void MainWindow::on_action_cut_triggered()
{
    getCurrentWidget()->cut();
}

void MainWindow::on_action_withdraw_triggered()
{
    getCurrentWidget()->withdraw();
}

void MainWindow::on_action_recover_triggered()
{
    getCurrentWidget()->recover();
}

void MainWindow::on_action_copy_triggered()
{
    getCurrentWidget()->copy();
}

void MainWindow::on_action_all_triggered()
{
    getCurrentWidget()->all_select();
}

void MainWindow::on_action_find_triggered()
{
    getCurrentWidget()->searchStart();
}

void MainWindow::on_action_replace_triggered()
{
   getCurrentWidget()->replaceStart();
}

void MainWindow::on_action_font_triggered()
{
    bool ok;
    QFont m_font=font;
    QFont f = QFontDialog::getFont(&ok, m_font, this, "设置显示字体");
    if (ok) {//检查用户是否成功选择了字体。如果用户点击了“确定”按钮并成功选择字体，则ok的值为true，代码中的if语句将执行
        m_font = f;
        font=f;
        for(int i=0;i<ui->tabWidget->count();i++)
        {
            getWidget(i)->setFont(font);
        }
        //ui->text_widget->setFont(m_font);// 将字体设置应用到IDE的相关部件上
        //  ui->compilerOutput->setFont(m_font);
    }
}

void MainWindow::on_action_openFolder_triggered()
{
    ui->file_widget->loaddir();
}

void MainWindow::on_action_saveAs_triggered()
{
    QString str=getCurrentWidget()->getText();//获取编辑区内容QString
    if(saveStringAs(str,this))
        getCurrentWidget()->is_change=false;
}

void MainWindow::on_action_openFile_triggered()
{
    // 使用QFileDialog::getOpenFileName()打开一个文件对话框，获取所选文件的路径
    QString path = QFileDialog::getOpenFileName();
    if(path.isEmpty()) {
        return; // 如果没有选择路径，则返回
    }
    file_open(path);
}


void MainWindow::on_action_save_triggered()
{
    QString str=getCurrentWidget()->getText();
    if(getCurrentWidget()->path!="")
    {
        saveString(str,getCurrentWidget()->path);
        getCurrentWidget()->is_change=false;
    }
    else
    {
        if(saveStringAs(str,this))
             getCurrentWidget()->is_change=false;
    }

}

void MainWindow::on_action_closeFile_triggered()
{
    if(getCurrentWidget()->is_change)
    {
        QString strInfo="是否保存"+getCurrentWidget()->name+"\n";
        QMessageBox::StandardButton  defaultBtn=QMessageBox::NoButton;
        QMessageBox::StandardButton result;
        result=QMessageBox::question(this, "提示", strInfo,QMessageBox::Cancel|QMessageBox::Yes,defaultBtn);
        if(result==QMessageBox::Yes)
        {
            on_action_save_triggered();    
        } 
    }
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(getWidget(index)->is_change)
    {
        QString strInfo="是否保存"+getWidget(index)->name+"\n";
        QMessageBox::StandardButton  defaultBtn=QMessageBox::NoButton;
        QMessageBox::StandardButton result;
        result=QMessageBox::question(this, "提示", strInfo,QMessageBox::Cancel|QMessageBox::Yes,defaultBtn);
        if(result==QMessageBox::Yes)
        {
            QString str=getWidget(index)->getText();
            if(getWidget(index)->path!="")
            {
                saveString(str,getWidget(index)->path);
                getWidget(index)->is_change=false;
            }
            else
            {
                if(saveStringAs(str,this))
                     getWidget(index)->is_change=false;
            }

        }
    }
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_action_runsetting_triggered()
{
    for(int i=0;i<ui->tabWidget->count();i++)
    {
        getWidget(i)->setRunSetting(is_show_IO);
    }
    is_show_IO=!is_show_IO;
}

void MainWindow::on_action_newFile_triggered()
{
    QModelIndex index=ui->file_widget->currentIndex();
    qDebug()<<index<<":"<<ui->file_widget->model.filePath(index);
    if(index.isValid())
        ui->file_widget->addfile(index);
    else
        newTab("new.c","","");
}


void MainWindow::on_action_mutipleRun_triggered()
{
    qDebug()<<"OK";
    QList <QFileInfo> file_list;
    QList <QString> name_list;
    QList <QString> path_list;
    QModelIndex index=ui->file_widget->currentIndex();
    int row=ui->file_widget->model.rowCount(index);
    qDebug()<<row;
    for(int i=0;i<row;i++)
    {
        QModelIndex now=ui->file_widget->model.index(i,0,index);
        //file_list.append(ui->file_widget->model.fileInfo(now));
        QFileInfo file=ui->file_widget->model.fileInfo(now);
        qDebug()<<file.suffix();
        if(file.suffix()=="cpp"||file.suffix()=="c")
        {

            name_list.append(file.fileName());
            path_list.append(file.absoluteFilePath());
        }
    }
    //   for(int j=0;j<name_list.length();j++)
    //   {
    //       qDebug()<<"name:"<<name_list.at(j);
    //       qDebug()<<"path:"<<path_list.at(j);
    //   }
    process pro;
    pro.mutiple(name_list,path_list);
}

void MainWindow::on_action_closeDir_triggered()
{
    ui->file_widget->reSetBlank();
}

void MainWindow::on_action_compile_triggered()
{
    if(getCurrentWidget()->is_change)
    {
        QString strInfo="是否保存"+getCurrentWidget()->name+"\n";
        QMessageBox::StandardButton  defaultBtn=QMessageBox::NoButton;
        QMessageBox::StandardButton result;
        result=QMessageBox::question(this, "提示", strInfo,QMessageBox::Cancel|QMessageBox::Yes,defaultBtn);
        if(result==QMessageBox::Yes)
        {
            on_action_save_triggered();
        }
    }
    process temp;
    QString path=getCurrentWidget()->path;
    if(path=="")
    {
        saveStringAs(getCurrentWidget()->getText(),this);
    }
    qDebug()<<path;
    temp.setLine(path);
    temp.serName(path.split(".")[0]);
    temp.compile();
}


void MainWindow::on_action_run_triggered()
{
    if(getCurrentWidget()->is_change)
    {
        QString strInfo="是否保存"+getCurrentWidget()->name+"\n";
        QMessageBox::StandardButton  defaultBtn=QMessageBox::NoButton;
        QMessageBox::StandardButton result;
        result=QMessageBox::question(this, "提示", strInfo,QMessageBox::Cancel|QMessageBox::Yes,defaultBtn);
        if(result==QMessageBox::Yes)
        {
            on_action_save_triggered();
        }
    }
    process temp;
    QString path=getCurrentWidget()->path;
    if(path=="")
    {
        saveStringAs(getCurrentWidget()->getText(),this);
    }
    qDebug()<<path;
    temp.setLine(path);
    temp.serName(path.split(".")[0]);
    temp.compile();

    QProcess te;
    QString command = "gnome-terminal";
    QStringList arguments;
    QStringList parts = path.split(".");
    QString programToRun = parts[0];

    arguments << "--disable-factory" << "--" << "bash" << "-c" << programToRun + "&& echo '\nPress Enter to Exit'  "" && read";

    te.setProcessChannelMode(QProcess::SeparateChannels); // 设置输入和输出通道分离
    te.start(command, arguments);


    if (te.waitForFinished(-1)) {
        qDebug() << "Process finished.";
    } else {
        qDebug() << "Process error:" << te.errorString();
    }
}


void MainWindow::on_actionFormat_triggered()
{
    QString name=getCurrentWidget()->name;
    QString p=getCurrentWidget()->path;
    process pro;
    pro.format(p,name);
}
