#ifndef CODEFORM_H
#define CODEFORM_H

#include <QWidget>
#include"searchform.h"
#include"replaceform.h"
#include"mainwindow.h"
namespace Ui {
class CodeForm;
}

class CodeForm : public QWidget
{
    Q_OBJECT

public:
    explicit CodeForm(QWidget *parent = nullptr);
    ~CodeForm();

//获取当前页面控件
    CodeForm* getWidget();
//获取当前页面文本
    void setText(QString);
    QString getText();
//页面编辑操作
    void paste();
    void copy();
    void cut();
    void withdraw();
    void all_select();
    void recover();
//查询、替换
    SearchForm* getSearchForm();
    replaceForm* getReplaceForm();
    void searchStart();
    void replaceStart();
//设置
    QFont Font();
    void setFont(QFont);
    void setRunSetting(bool);
    QList<QPair<int, QString>> deletedLines; // 存储被删除的行号和文本内容

public slots:
    void start_search(QString);
    void stop_search(QString);
    void replace_func(QString,QString);
    void isChanged();
    void search_Next(QString);
    void handleButtonClick();
    void addContent(int line, QString content);
    void changeFold();
public:
    Ui::CodeForm *ui;
    QString path="";
    QString name="";
    bool is_change=false;
    bool is_fold=false;

};

#endif // CODEFORM_H
