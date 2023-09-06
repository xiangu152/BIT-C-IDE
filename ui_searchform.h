/********************************************************************************
** Form generated from reading UI file 'searchform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFORM_H
#define UI_SEARCHFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchForm
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *SearchForm)
    {
        if (SearchForm->objectName().isEmpty())
            SearchForm->setObjectName(QString::fromUtf8("SearchForm"));
        SearchForm->resize(490, 67);
        horizontalLayout = new QHBoxLayout(SearchForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(SearchForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(SearchForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(SearchForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(SearchForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(SearchForm);

        QMetaObject::connectSlotsByName(SearchForm);
    } // setupUi

    void retranslateUi(QWidget *SearchForm)
    {
        SearchForm->setWindowTitle(QApplication::translate("SearchForm", "Form", nullptr));
        pushButton->setText(QApplication::translate("SearchForm", "\346\237\245\346\211\276", nullptr));
        pushButton_3->setText(QApplication::translate("SearchForm", "\344\270\213\344\270\200\344\270\252", nullptr));
        pushButton_2->setText(QApplication::translate("SearchForm", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchForm: public Ui_SearchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFORM_H
