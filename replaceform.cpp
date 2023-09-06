#include "replaceform.h"
#include "ui_replaceform.h"

replaceForm::replaceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::replaceForm)
{
    ui->setupUi(this);
}

replaceForm::~replaceForm()
{
    delete ui;
}

void replaceForm::on_pushButton_clicked()
{
    emit replace(ui->lineEdit->text(),ui->lineEdit_2->text());
   // emit inreplaceword(ui->lineEdit_2->text());
}

void replaceForm::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    this->close();
}
