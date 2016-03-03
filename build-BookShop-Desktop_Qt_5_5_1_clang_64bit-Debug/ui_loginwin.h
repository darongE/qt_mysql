/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginwin
{
public:
    QLabel *label1;
    QLabel *label2;
    QLineEdit *user;
    QLineEdit *pwd;
    QPushButton *pbLogin;
    QPushButton *pbCancle;

    void setupUi(QDialog *loginwin)
    {
        if (loginwin->objectName().isEmpty())
            loginwin->setObjectName(QStringLiteral("loginwin"));
        loginwin->resize(335, 246);
        label1 = new QLabel(loginwin);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(80, 70, 59, 16));
        label2 = new QLabel(loginwin);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(80, 110, 59, 16));
        user = new QLineEdit(loginwin);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(140, 70, 113, 21));
        pwd = new QLineEdit(loginwin);
        pwd->setObjectName(QStringLiteral("pwd"));
        pwd->setGeometry(QRect(140, 110, 113, 21));
        pbLogin = new QPushButton(loginwin);
        pbLogin->setObjectName(QStringLiteral("pbLogin"));
        pbLogin->setGeometry(QRect(70, 160, 81, 32));
        pbCancle = new QPushButton(loginwin);
        pbCancle->setObjectName(QStringLiteral("pbCancle"));
        pbCancle->setGeometry(QRect(180, 160, 81, 32));

        retranslateUi(loginwin);
        QObject::connect(pbLogin, SIGNAL(clicked()), loginwin, SLOT(login()));
        QObject::connect(pbCancle, SIGNAL(clicked()), loginwin, SLOT(close()));

        QMetaObject::connectSlotsByName(loginwin);
    } // setupUi

    void retranslateUi(QDialog *loginwin)
    {
        loginwin->setWindowTitle(QApplication::translate("loginwin", "\347\256\241\347\220\206\345\221\230\347\231\273\351\231\206", 0));
        label1->setText(QApplication::translate("loginwin", "\347\224\250\346\210\267\345\220\215", 0));
        label2->setText(QApplication::translate("loginwin", "\345\257\206\347\240\201", 0));
        pbLogin->setText(QApplication::translate("loginwin", "\347\231\273\351\231\206", 0));
        pbCancle->setText(QApplication::translate("loginwin", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class loginwin: public Ui_loginwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
