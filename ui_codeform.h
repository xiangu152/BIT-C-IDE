/********************************************************************************
** Form generated from reading UI file 'codeform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEFORM_H
#define UI_CODEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "codeeditor.h"
#include "replaceform.h"
#include "searchform.h"

QT_BEGIN_NAMESPACE

class Ui_CodeForm
{
public:
    QGridLayout *gridLayout;
    CodeEditor *text_widget;
    QFormLayout *formLayout;
    SearchForm *searchForm;
    replaceForm *replaceform;
    QWidget *IO_widget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;

    void setupUi(QWidget *CodeForm)
    {
        if (CodeForm->objectName().isEmpty())
            CodeForm->setObjectName(QString::fromUtf8("CodeForm"));
        CodeForm->resize(753, 622);
        gridLayout = new QGridLayout(CodeForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        text_widget = new CodeEditor(CodeForm);
        text_widget->setObjectName(QString::fromUtf8("text_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(text_widget->sizePolicy().hasHeightForWidth());
        text_widget->setSizePolicy(sizePolicy);
        text_widget->setMinimumSize(QSize(781, 430));
        text_widget->setMaximumSize(QSize(16777215, 16777215));
        formLayout = new QFormLayout(text_widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        searchForm = new SearchForm(text_widget);
        searchForm->setObjectName(QString::fromUtf8("searchForm"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(searchForm->sizePolicy().hasHeightForWidth());
        searchForm->setSizePolicy(sizePolicy1);
        searchForm->setMinimumSize(QSize(490, 67));
        searchForm->setMaximumSize(QSize(490, 67));
        searchForm->setLayoutDirection(Qt::LeftToRight);

        formLayout->setWidget(0, QFormLayout::LabelRole, searchForm);

        replaceform = new replaceForm(text_widget);
        replaceform->setObjectName(QString::fromUtf8("replaceform"));
        replaceform->setMinimumSize(QSize(590, 78));
        replaceform->setMaximumSize(QSize(590, 78));

        formLayout->setWidget(1, QFormLayout::LabelRole, replaceform);


        gridLayout->addWidget(text_widget, 0, 0, 1, 1);

        IO_widget = new QWidget(CodeForm);
        IO_widget->setObjectName(QString::fromUtf8("IO_widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(IO_widget->sizePolicy().hasHeightForWidth());
        IO_widget->setSizePolicy(sizePolicy2);
        IO_widget->setMinimumSize(QSize(781, 200));
        IO_widget->setMaximumSize(QSize(16777215, 200));
        IO_widget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(IO_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(IO_widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);
        textBrowser->setMinimumSize(QSize(781, 0));

        verticalLayout->addWidget(textBrowser);

        lineEdit = new QLineEdit(IO_widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(781, 0));

        verticalLayout->addWidget(lineEdit);


        gridLayout->addWidget(IO_widget, 1, 0, 1, 1);


        retranslateUi(CodeForm);

        QMetaObject::connectSlotsByName(CodeForm);
    } // setupUi

    void retranslateUi(QWidget *CodeForm)
    {
        CodeForm->setWindowTitle(QCoreApplication::translate("CodeForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CodeForm: public Ui_CodeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEFORM_H
