#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<highlighter.h>
#include"codeform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CodeForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    CodeForm* getCurrentWidget();
    CodeForm* getWidget(int);
    void newTab(QString,QString,QString);


    void file_open(QString);

private slots:

    void on_action_find_triggered();

    void on_action_replace_triggered();

    void on_action_copy_triggered();

    void on_action_paste_triggered();

    void on_action_cut_triggered();

    void on_action_withdraw_triggered();

    void on_action_recover_triggered();

    void on_action_font_triggered();

    void on_action_saveAs_triggered();

    void on_action_openFile_triggered();

    void on_action_openFolder_triggered();

    void on_action_all_triggered();

    void on_action_save_triggered();

    void on_action_closeFile_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_action_runsetting_triggered();

    void on_action_newFile_triggered();


   // void on_action111_triggered();

    void on_action_mutipleRun_triggered();

    void on_action_closeDir_triggered();

    void on_action_compile_triggered();

    void on_action_run_triggered();


    void on_action_format_triggered();

    void on_action_fold_triggered();

private:
    Ui::MainWindow *ui;
    Highlighter *highlighter;
    QString path_now="";
    QFont font;
    bool is_show_IO=true;
};
#endif // MAINWINDOW_H
