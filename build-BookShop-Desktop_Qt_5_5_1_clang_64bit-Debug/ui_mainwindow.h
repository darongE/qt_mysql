/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pblogin;
    QPushButton *pbinfo;
    QPushButton *quit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(309, 224);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pblogin = new QPushButton(centralwidget);
        pblogin->setObjectName(QStringLiteral("pblogin"));
        pblogin->setGeometry(QRect(170, 40, 115, 32));
        pbinfo = new QPushButton(centralwidget);
        pbinfo->setObjectName(QStringLiteral("pbinfo"));
        pbinfo->setGeometry(QRect(170, 100, 115, 32));
        quit = new QPushButton(centralwidget);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(210, 150, 81, 32));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pbinfo, SIGNAL(clicked()), MainWindow, SLOT(info()));
        QObject::connect(pblogin, SIGNAL(clicked()), MainWindow, SLOT(login()));
        QObject::connect(quit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\271\246\345\272\227\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        pblogin->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\347\231\273\351\231\206", 0));
        pbinfo->setText(QApplication::translate("MainWindow", "\345\233\276\344\271\246\344\277\241\346\201\257\346\237\245\350\257\242", 0));
        quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
