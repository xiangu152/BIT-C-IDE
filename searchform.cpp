#include "searchform.h"
#include "ui_searchform.h"
#include<QMessageBox>
#include<QDebug>
SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);



}

SearchForm::~SearchForm()
{
    delete ui;
}

void SearchForm::on_pushButton_clicked()
{
   emit stopSearch(QString(text));
   emit startSearch(QString(ui->lineEdit->text()));
   text=ui->lineEdit->text();
}


void SearchForm::on_pushButton_2_clicked()
{
    emit stopSearch(QString(ui->lineEdit->text()));
    ui->lineEdit->clear();
    this->close();
}

void SearchForm::on_pushButton_3_clicked()
{
     emit searchNext(QString(ui->lineEdit->text()));
    text=ui->lineEdit->text();
}
