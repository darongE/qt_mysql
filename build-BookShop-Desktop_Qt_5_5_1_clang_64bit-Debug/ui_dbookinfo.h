/********************************************************************************
** Form generated from reading UI file 'dbookinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBOOKINFO_H
#define UI_DBOOKINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DBookInfo
{
public:
    QCheckBox *cbByName;
    QLineEdit *leName;
    QCheckBox *cbByPress;
    QLineEdit *lePress;
    QCheckBox *cbByAuthor;
    QLineEdit *leAuthor;
    QPushButton *pbQuery;
    QPushButton *pbReset;
    QPushButton *pbShowAll;
    QTableView *BookList;
    QLabel *label;
    QComboBox *cbISBNList;
    QPushButton *pbQueryByISBN;

    void setupUi(QDialog *DBookInfo)
    {
        if (DBookInfo->objectName().isEmpty())
            DBookInfo->setObjectName(QStringLiteral("DBookInfo"));
        DBookInfo->resize(720, 440);
        cbByName = new QCheckBox(DBookInfo);
        cbByName->setObjectName(QStringLiteral("cbByName"));
        cbByName->setGeometry(QRect(20, 30, 61, 20));
        leName = new QLineEdit(DBookInfo);
        leName->setObjectName(QStringLiteral("leName"));
        leName->setEnabled(false);
        leName->setGeometry(QRect(90, 30, 131, 21));
        cbByPress = new QCheckBox(DBookInfo);
        cbByPress->setObjectName(QStringLiteral("cbByPress"));
        cbByPress->setGeometry(QRect(250, 30, 81, 20));
        lePress = new QLineEdit(DBookInfo);
        lePress->setObjectName(QStringLiteral("lePress"));
        lePress->setEnabled(false);
        lePress->setGeometry(QRect(330, 30, 131, 21));
        cbByAuthor = new QCheckBox(DBookInfo);
        cbByAuthor->setObjectName(QStringLiteral("cbByAuthor"));
        cbByAuthor->setGeometry(QRect(490, 30, 61, 20));
        leAuthor = new QLineEdit(DBookInfo);
        leAuthor->setObjectName(QStringLiteral("leAuthor"));
        leAuthor->setEnabled(false);
        leAuthor->setGeometry(QRect(560, 30, 131, 21));
        pbQuery = new QPushButton(DBookInfo);
        pbQuery->setObjectName(QStringLiteral("pbQuery"));
        pbQuery->setGeometry(QRect(20, 70, 71, 32));
        pbReset = new QPushButton(DBookInfo);
        pbReset->setObjectName(QStringLiteral("pbReset"));
        pbReset->setGeometry(QRect(100, 70, 71, 32));
        pbShowAll = new QPushButton(DBookInfo);
        pbShowAll->setObjectName(QStringLiteral("pbShowAll"));
        pbShowAll->setGeometry(QRect(180, 70, 91, 32));
        BookList = new QTableView(DBookInfo);
        BookList->setObjectName(QStringLiteral("BookList"));
        BookList->setGeometry(QRect(3, 110, 715, 326));
        label = new QLabel(DBookInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(410, 70, 41, 21));
        cbISBNList = new QComboBox(DBookInfo);
        cbISBNList->setObjectName(QStringLiteral("cbISBNList"));
        cbISBNList->setGeometry(QRect(450, 70, 161, 26));
        pbQueryByISBN = new QPushButton(DBookInfo);
        pbQueryByISBN->setObjectName(QStringLiteral("pbQueryByISBN"));
        pbQueryByISBN->setGeometry(QRect(620, 70, 71, 32));

        retranslateUi(DBookInfo);
        QObject::connect(pbShowAll, SIGNAL(clicked()), DBookInfo, SLOT(showAll()));
        QObject::connect(pbReset, SIGNAL(clicked()), DBookInfo, SLOT(reset()));
        QObject::connect(cbByName, SIGNAL(toggled(bool)), DBookInfo, SLOT(setEnable()));
        QObject::connect(cbByPress, SIGNAL(toggled(bool)), DBookInfo, SLOT(setEnable()));
        QObject::connect(cbByAuthor, SIGNAL(toggled(bool)), DBookInfo, SLOT(setEnable()));
        QObject::connect(pbQuery, SIGNAL(clicked()), DBookInfo, SLOT(query()));
        QObject::connect(pbQueryByISBN, SIGNAL(clicked()), DBookInfo, SLOT(queryByISBN()));

        QMetaObject::connectSlotsByName(DBookInfo);
    } // setupUi

    void retranslateUi(QDialog *DBookInfo)
    {
        DBookInfo->setWindowTitle(QApplication::translate("DBookInfo", "\345\233\276\344\271\246\344\277\241\346\201\257\346\237\245\350\257\242", 0));
        cbByName->setText(QApplication::translate("DBookInfo", "\346\214\211\344\271\246\345\220\215", 0));
        cbByPress->setText(QApplication::translate("DBookInfo", "\346\214\211\345\207\272\347\211\210\347\244\276", 0));
        cbByAuthor->setText(QApplication::translate("DBookInfo", "\346\214\211\344\275\234\350\200\205", 0));
        pbQuery->setText(QApplication::translate("DBookInfo", "\346\237\245\350\257\242", 0));
        pbReset->setText(QApplication::translate("DBookInfo", "\351\207\215\347\275\256", 0));
        pbShowAll->setText(QApplication::translate("DBookInfo", "\346\230\276\347\244\272\346\211\200\346\234\211", 0));
        label->setText(QApplication::translate("DBookInfo", "ISBN", 0));
        pbQueryByISBN->setText(QApplication::translate("DBookInfo", "\345\256\232\344\275\215", 0));
    } // retranslateUi

};

namespace Ui {
    class DBookInfo: public Ui_DBookInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBOOKINFO_H
