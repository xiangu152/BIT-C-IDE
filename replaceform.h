#ifndef REPLACEFORM_H
#define REPLACEFORM_H

#include <QWidget>

namespace Ui {
class replaceForm;
}

class replaceForm : public QWidget
{
    Q_OBJECT

public:
    explicit replaceForm(QWidget *parent = nullptr);
    ~replaceForm();

signals:
    void replace(QString,QString);



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::replaceForm *ui;
};

#endif // REPLACEFORM_H
