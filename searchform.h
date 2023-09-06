#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QWidget>

namespace Ui {
class SearchForm;
}

class SearchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = nullptr);
    ~SearchForm();

signals:
    void startSearch(QString searchtext);
    void stopSearch(QString searchtext);
    void searchNext(QString searchtext);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SearchForm *ui;
    QString text="";
};

#endif // SEARCHFORM_H
