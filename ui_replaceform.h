/********************************************************************************
** Form generated from reading UI file 'replaceform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEFORM_H
#define UI_REPLACEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replaceForm
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *replaceForm)
    {
        if (replaceForm->objectName().isEmpty())
            replaceForm->setObjectName(QString::fromUtf8("replaceForm"));
        replaceForm->resize(590, 78);
        widget = new QWidget(replaceForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 590, 78));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 222)"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(replaceForm);

        QMetaObject::connectSlotsByName(replaceForm);
    } // setupUi

    void retranslateUi(QWidget *replaceForm)
    {
        replaceForm->setWindowTitle(QCoreApplication::translate("replaceForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("replaceForm", "\350\242\253\346\233\277\346\215\242\350\257\215", nullptr));
        label_2->setText(QCoreApplication::translate("replaceForm", "\346\233\277\346\215\242\350\257\215", nullptr));
        pushButton->setText(QCoreApplication::translate("replaceForm", "\346\233\277\346\215\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("replaceForm", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class replaceForm: public Ui_replaceForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEFORM_H
