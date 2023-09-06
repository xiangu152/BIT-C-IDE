/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "mytree.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_newFile;
    QAction *action_openFile;
    QAction *action_newFolder;
    QAction *action_openFolder;
    QAction *action_closeFile;
    QAction *action_exit;
    QAction *action_withdraw;
    QAction *action_recover;
    QAction *action_cut;
    QAction *action_copy;
    QAction *action_paste;
    QAction *action_all;
    QAction *action_compile;
    QAction *action_run;
    QAction *action_find;
    QAction *action_replace;
    QAction *action_save;
    QAction *action_saveAs;
    QAction *action_font;
    QAction *action_runsetting;
    QAction *action_mutipleRun;
    QAction *action_closeDir;
    QAction *actionFormat;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    myTree *file_widget;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_editor;
    QMenu *menu_run;
    QMenu *menu_tool;
    QMenu *menu_setting;
    QMenu *menu_help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1150, 750);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        action_newFile = new QAction(MainWindow);
        action_newFile->setObjectName(QString::fromUtf8("action_newFile"));
        action_openFile = new QAction(MainWindow);
        action_openFile->setObjectName(QString::fromUtf8("action_openFile"));
        action_newFolder = new QAction(MainWindow);
        action_newFolder->setObjectName(QString::fromUtf8("action_newFolder"));
        action_openFolder = new QAction(MainWindow);
        action_openFolder->setObjectName(QString::fromUtf8("action_openFolder"));
        action_closeFile = new QAction(MainWindow);
        action_closeFile->setObjectName(QString::fromUtf8("action_closeFile"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_withdraw = new QAction(MainWindow);
        action_withdraw->setObjectName(QString::fromUtf8("action_withdraw"));
        action_recover = new QAction(MainWindow);
        action_recover->setObjectName(QString::fromUtf8("action_recover"));
        action_cut = new QAction(MainWindow);
        action_cut->setObjectName(QString::fromUtf8("action_cut"));
        action_copy = new QAction(MainWindow);
        action_copy->setObjectName(QString::fromUtf8("action_copy"));
        action_paste = new QAction(MainWindow);
        action_paste->setObjectName(QString::fromUtf8("action_paste"));
        action_all = new QAction(MainWindow);
        action_all->setObjectName(QString::fromUtf8("action_all"));
        action_compile = new QAction(MainWindow);
        action_compile->setObjectName(QString::fromUtf8("action_compile"));
        action_run = new QAction(MainWindow);
        action_run->setObjectName(QString::fromUtf8("action_run"));
        action_find = new QAction(MainWindow);
        action_find->setObjectName(QString::fromUtf8("action_find"));
        action_replace = new QAction(MainWindow);
        action_replace->setObjectName(QString::fromUtf8("action_replace"));
        action_save = new QAction(MainWindow);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_saveAs = new QAction(MainWindow);
        action_saveAs->setObjectName(QString::fromUtf8("action_saveAs"));
        action_font = new QAction(MainWindow);
        action_font->setObjectName(QString::fromUtf8("action_font"));
        action_runsetting = new QAction(MainWindow);
        action_runsetting->setObjectName(QString::fromUtf8("action_runsetting"));
        action_mutipleRun = new QAction(MainWindow);
        action_mutipleRun->setObjectName(QString::fromUtf8("action_mutipleRun"));
        action_closeDir = new QAction(MainWindow);
        action_closeDir->setObjectName(QString::fromUtf8("action_closeDir"));
        actionFormat = new QAction(MainWindow);
        actionFormat->setObjectName(QString::fromUtf8("actionFormat"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        file_widget = new myTree(centralwidget);
        file_widget->setObjectName(QString::fromUtf8("file_widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(file_widget->sizePolicy().hasHeightForWidth());
        file_widget->setSizePolicy(sizePolicy1);
        file_widget->setMinimumSize(QSize(340, 681));

        horizontalLayout->addWidget(file_widget);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabsClosable(true);

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        tabWidget->raise();
        file_widget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1150, 28));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(true);
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_editor = new QMenu(menubar);
        menu_editor->setObjectName(QString::fromUtf8("menu_editor"));
        menu_run = new QMenu(menubar);
        menu_run->setObjectName(QString::fromUtf8("menu_run"));
        menu_tool = new QMenu(menubar);
        menu_tool->setObjectName(QString::fromUtf8("menu_tool"));
        menu_setting = new QMenu(menubar);
        menu_setting->setObjectName(QString::fromUtf8("menu_setting"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_editor->menuAction());
        menubar->addAction(menu_run->menuAction());
        menubar->addAction(menu_tool->menuAction());
        menubar->addAction(menu_setting->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(action_newFile);
        menu_file->addAction(action_newFolder);
        menu_file->addAction(action_openFile);
        menu_file->addAction(action_openFolder);
        menu_file->addAction(action_save);
        menu_file->addAction(action_saveAs);
        menu_file->addAction(action_closeFile);
        menu_file->addAction(action_closeDir);
        menu_file->addAction(action_exit);
        menu_editor->addAction(action_withdraw);
        menu_editor->addAction(action_recover);
        menu_editor->addAction(action_cut);
        menu_editor->addAction(action_copy);
        menu_editor->addAction(action_paste);
        menu_editor->addAction(action_all);
        menu_run->addAction(action_compile);
        menu_run->addAction(action_run);
        menu_run->addAction(action_mutipleRun);
        menu_tool->addAction(action_find);
        menu_tool->addAction(action_replace);
        menu_tool->addAction(actionFormat);
        menu_setting->addAction(action_font);
        menu_setting->addAction(action_runsetting);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_newFile->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
        action_openFile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        action_newFolder->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266\345\244\271", nullptr));
        action_openFolder->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        action_closeFile->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\226\207\344\273\266", nullptr));
        action_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        action_withdraw->setText(QApplication::translate("MainWindow", "\346\222\244\345\233\236", nullptr));
#ifndef QT_NO_SHORTCUT
        action_withdraw->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        action_recover->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215", nullptr));
#ifndef QT_NO_SHORTCUT
        action_recover->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        action_cut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#ifndef QT_NO_SHORTCUT
        action_cut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        action_copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#ifndef QT_NO_SHORTCUT
        action_copy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        action_paste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#ifndef QT_NO_SHORTCUT
        action_paste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        action_all->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        action_compile->setText(QApplication::translate("MainWindow", "\347\274\226\350\257\221", nullptr));
        action_run->setText(QApplication::translate("MainWindow", "\347\274\226\350\257\221\350\277\220\350\241\214", nullptr));
        action_find->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
        action_replace->setText(QApplication::translate("MainWindow", "\346\233\277\346\215\242", nullptr));
        action_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#ifndef QT_NO_SHORTCUT
        action_save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_saveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        action_font->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
        action_runsetting->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200/\345\205\263\351\227\255\347\274\226\350\257\221\346\240\217", nullptr));
        action_mutipleRun->setText(QApplication::translate("MainWindow", "\345\244\232\346\226\207\344\273\266\347\274\226\350\257\221", nullptr));
        action_closeDir->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\226\207\344\273\266\345\244\271", nullptr));
        actionFormat->setText(QApplication::translate("MainWindow", "Format", nullptr));
        menu_file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_editor->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_run->setTitle(QApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
        menu_tool->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        menu_setting->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        menu_help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
