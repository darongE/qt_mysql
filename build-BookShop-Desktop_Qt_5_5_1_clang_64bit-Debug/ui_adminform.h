/********************************************************************************
** Form generated from reading UI file 'adminform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminForm
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *Reset;
    QCheckBox *ckbvip;
    QPushButton *Add;
    QComboBox *cbvip;
    QTableWidget *tableWidget;
    QComboBox *ISBN;
    QPushButton *Finish;
    QSpinBox *Num;
    QWidget *tab_2;
    QLabel *storage;
    QLabel *label_10;
    QLineEdit *leAuthor;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lePress;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *leISBN;
    QPushButton *pbReset;
    QLabel *label_15;
    QLineEdit *leBname;
    QComboBox *cbISBN;
    QLabel *label_16;
    QCheckBox *isExist;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QRadioButton *rbyes;
    QRadioButton *rbno;
    QPushButton *pbRepln;
    QDateEdit *date;
    QRadioButton *rbhide;
    QSpinBox *sbRepln;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pbCover;
    QDoubleSpinBox *sbPrice;
    QWidget *tab_3;
    QLabel *label_4;
    QPushButton *save;
    QRadioButton *rbm;
    QPushButton *reset;
    QPushButton *del;
    QLabel *label_8;
    QLineEdit *leName;
    QPushButton *add;
    QComboBox *cbvipid;
    QRadioButton *rbf;
    QLineEdit *leEmail;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_6;
    QSpinBox *sbLevel;
    QLabel *label_9;
    QSpinBox *sbScore;
    QLineEdit *lePhone;
    QCheckBox *ckbvipid;
    QDateEdit *birth;
    QRadioButton *rbh;
    QLabel *label_5;
    QWidget *tab_4;
    QDateEdit *date1;
    QDateEdit *date2;
    QLabel *label;
    QLabel *label_23;
    QLabel *label_24;
    QComboBox *cbItem;
    QPushButton *Query;
    QPushButton *Del;
    QTableView *tradeList;
    QPushButton *showAll;
    QWidget *tab_5;
    QDateEdit *Date2;
    QLabel *label_25;
    QDateEdit *Date1;
    QLabel *label_26;
    QRadioButton *rbDay;
    QRadioButton *rbMonth;
    QRadioButton *rbYear;
    QPushButton *empty;
    QPushButton *display;
    QPushButton *query;
    QLabel *label_20;
    QTableWidget *incomeList;
    QPushButton *pbQuit;

    void setupUi(QWidget *adminForm)
    {
        if (adminForm->objectName().isEmpty())
            adminForm->setObjectName(QStringLiteral("adminForm"));
        adminForm->resize(710, 450);
        tabWidget = new QTabWidget(adminForm);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 709, 406));
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(50, 40, 41, 16));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(270, 40, 41, 16));
        Reset = new QPushButton(tab);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setGeometry(QRect(500, 40, 71, 32));
        ckbvip = new QCheckBox(tab);
        ckbvip->setObjectName(QStringLiteral("ckbvip"));
        ckbvip->setGeometry(QRect(50, 0, 61, 20));
        Add = new QPushButton(tab);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setGeometry(QRect(420, 40, 71, 32));
        cbvip = new QComboBox(tab);
        cbvip->setObjectName(QStringLiteral("cbvip"));
        cbvip->setEnabled(false);
        cbvip->setGeometry(QRect(120, 0, 101, 26));
        cbvip->setInsertPolicy(QComboBox::InsertAtBottom);
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 80, 703, 297));
        ISBN = new QComboBox(tab);
        ISBN->setObjectName(QStringLiteral("ISBN"));
        ISBN->setGeometry(QRect(90, 40, 161, 26));
        Finish = new QPushButton(tab);
        Finish->setObjectName(QStringLiteral("Finish"));
        Finish->setGeometry(QRect(580, 40, 71, 32));
        Num = new QSpinBox(tab);
        Num->setObjectName(QStringLiteral("Num"));
        Num->setGeometry(QRect(310, 40, 61, 24));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        storage = new QLabel(tab_2);
        storage->setObjectName(QStringLiteral("storage"));
        storage->setGeometry(QRect(340, 304, 101, 16));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(290, 270, 65, 16));
        leAuthor = new QLineEdit(tab_2);
        leAuthor->setObjectName(QStringLiteral("leAuthor"));
        leAuthor->setGeometry(QRect(340, 150, 125, 21));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(342, 65, 64, 16));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(290, 230, 39, 16));
        lePress = new QLineEdit(tab_2);
        lePress->setObjectName(QStringLiteral("lePress"));
        lePress->setGeometry(QRect(340, 190, 125, 21));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(290, 110, 39, 16));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(505, 304, 52, 16));
        leISBN = new QLineEdit(tab_2);
        leISBN->setObjectName(QStringLiteral("leISBN"));
        leISBN->setGeometry(QRect(410, 65, 151, 21));
        pbReset = new QPushButton(tab_2);
        pbReset->setObjectName(QStringLiteral("pbReset"));
        pbReset->setGeometry(QRect(520, 340, 68, 32));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(290, 190, 52, 16));
        leBname = new QLineEdit(tab_2);
        leBname->setObjectName(QStringLiteral("leBname"));
        leBname->setGeometry(QRect(340, 110, 221, 21));
        cbISBN = new QComboBox(tab_2);
        cbISBN->setObjectName(QStringLiteral("cbISBN"));
        cbISBN->setEnabled(false);
        cbISBN->setGeometry(QRect(406, 26, 161, 26));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(290, 26, 45, 16));
        isExist = new QCheckBox(tab_2);
        isExist->setObjectName(QStringLiteral("isExist"));
        isExist->setGeometry(QRect(340, 26, 64, 20));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(290, 304, 52, 16));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(290, 150, 39, 16));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(500, 193, 65, 16));
        rbyes = new QRadioButton(tab_2);
        rbyes->setObjectName(QStringLiteral("rbyes"));
        rbyes->setGeometry(QRect(360, 266, 38, 20));
        rbno = new QRadioButton(tab_2);
        rbno->setObjectName(QStringLiteral("rbno"));
        rbno->setGeometry(QRect(410, 266, 38, 20));
        pbRepln = new QPushButton(tab_2);
        pbRepln->setObjectName(QStringLiteral("pbRepln"));
        pbRepln->setGeometry(QRect(610, 340, 68, 32));
        date = new QDateEdit(tab_2);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(560, 190, 121, 24));
        date->setLayoutDirection(Qt::LeftToRight);
        date->setMaximumDateTime(QDateTime(QDate(2016, 1, 1), QTime(23, 59, 59)));
        date->setMaximumDate(QDate(2016, 1, 1));
        rbhide = new QRadioButton(tab_2);
        rbhide->setObjectName(QStringLiteral("rbhide"));
        rbhide->setGeometry(QRect(460, 266, 61, 20));
        sbRepln = new QSpinBox(tab_2);
        sbRepln->setObjectName(QStringLiteral("sbRepln"));
        sbRepln->setGeometry(QRect(560, 300, 121, 24));
        sbRepln->setMaximum(9999);
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 20, 225, 311));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 223, 309));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pbCover = new QPushButton(tab_2);
        pbCover->setObjectName(QStringLiteral("pbCover"));
        pbCover->setGeometry(QRect(130, 340, 131, 32));
        sbPrice = new QDoubleSpinBox(tab_2);
        sbPrice->setObjectName(QStringLiteral("sbPrice"));
        sbPrice->setGeometry(QRect(340, 230, 131, 24));
        sbPrice->setDecimals(1);
        sbPrice->setMaximum(1000);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 170, 65, 16));
        save = new QPushButton(tab_3);
        save->setObjectName(QStringLiteral("save"));
        save->setEnabled(false);
        save->setGeometry(QRect(270, 335, 94, 32));
        rbm = new QRadioButton(tab_3);
        rbm->setObjectName(QStringLiteral("rbm"));
        rbm->setGeometry(QRect(242, 130, 38, 20));
        reset = new QPushButton(tab_3);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(370, 335, 81, 32));
        del = new QPushButton(tab_3);
        del->setObjectName(QStringLiteral("del"));
        del->setEnabled(false);
        del->setGeometry(QRect(460, 335, 91, 32));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 290, 39, 16));
        leName = new QLineEdit(tab_3);
        leName->setObjectName(QStringLiteral("leName"));
        leName->setGeometry(QRect(240, 90, 113, 21));
        add = new QPushButton(tab_3);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(170, 335, 94, 32));
        cbvipid = new QComboBox(tab_3);
        cbvipid->setObjectName(QStringLiteral("cbvipid"));
        cbvipid->setEnabled(false);
        cbvipid->setGeometry(QRect(240, 20, 104, 26));
        rbf = new QRadioButton(tab_3);
        rbf->setObjectName(QStringLiteral("rbf"));
        rbf->setGeometry(QRect(290, 130, 38, 20));
        leEmail = new QLineEdit(tab_3);
        leEmail->setObjectName(QStringLiteral("leEmail"));
        leEmail->setGeometry(QRect(240, 250, 261, 21));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 90, 39, 16));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 250, 47, 16));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 60, 52, 16));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 210, 65, 16));
        sbLevel = new QSpinBox(tab_3);
        sbLevel->setObjectName(QStringLiteral("sbLevel"));
        sbLevel->setGeometry(QRect(431, 290, 71, 24));
        sbLevel->setMinimum(1);
        sbLevel->setMaximum(5);
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(380, 290, 39, 16));
        sbScore = new QSpinBox(tab_3);
        sbScore->setObjectName(QStringLiteral("sbScore"));
        sbScore->setGeometry(QRect(240, 290, 71, 24));
        lePhone = new QLineEdit(tab_3);
        lePhone->setObjectName(QStringLiteral("lePhone"));
        lePhone->setGeometry(QRect(240, 210, 113, 21));
        ckbvipid = new QCheckBox(tab_3);
        ckbvipid->setObjectName(QStringLiteral("ckbvipid"));
        ckbvipid->setGeometry(QRect(170, 20, 61, 20));
        birth = new QDateEdit(tab_3);
        birth->setObjectName(QStringLiteral("birth"));
        birth->setGeometry(QRect(240, 170, 110, 24));
        birth->setMinimumDateTime(QDateTime(QDate(1920, 1, 1), QTime(0, 0, 0)));
        birth->setMaximumDate(QDate(2015, 10, 31));
        birth->setMinimumDate(QDate(1920, 1, 1));
        birth->setDate(QDate(1980, 1, 1));
        rbh = new QRadioButton(tab_3);
        rbh->setObjectName(QStringLiteral("rbh"));
        rbh->setGeometry(QRect(340, 130, 51, 20));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 130, 59, 16));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        date1 = new QDateEdit(tab_4);
        date1->setObjectName(QStringLiteral("date1"));
        date1->setGeometry(QRect(380, 10, 110, 24));
        date1->setDateTime(QDateTime(QDate(2014, 1, 1), QTime(0, 0, 0)));
        date2 = new QDateEdit(tab_4);
        date2->setObjectName(QStringLiteral("date2"));
        date2->setGeometry(QRect(530, 10, 110, 24));
        date2->setDateTime(QDateTime(QDate(2016, 1, 1), QTime(0, 0, 0)));
        label = new QLabel(tab_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 14, 59, 16));
        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(500, 14, 21, 16));
        label_24 = new QLabel(tab_4);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(90, 14, 59, 16));
        cbItem = new QComboBox(tab_4);
        cbItem->setObjectName(QStringLiteral("cbItem"));
        cbItem->setGeometry(QRect(160, 10, 104, 26));
        Query = new QPushButton(tab_4);
        Query->setObjectName(QStringLiteral("Query"));
        Query->setGeometry(QRect(440, 45, 81, 32));
        Del = new QPushButton(tab_4);
        Del->setObjectName(QStringLiteral("Del"));
        Del->setGeometry(QRect(550, 45, 81, 32));
        tradeList = new QTableView(tab_4);
        tradeList->setObjectName(QStringLiteral("tradeList"));
        tradeList->setGeometry(QRect(0, 80, 703, 297));
        showAll = new QPushButton(tab_4);
        showAll->setObjectName(QStringLiteral("showAll"));
        showAll->setGeometry(QRect(320, 45, 91, 32));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        Date2 = new QDateEdit(tab_5);
        Date2->setObjectName(QStringLiteral("Date2"));
        Date2->setGeometry(QRect(550, 16, 110, 24));
        Date2->setDateTime(QDateTime(QDate(2016, 1, 1), QTime(0, 0, 0)));
        label_25 = new QLabel(tab_5);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(520, 20, 21, 16));
        Date1 = new QDateEdit(tab_5);
        Date1->setObjectName(QStringLiteral("Date1"));
        Date1->setGeometry(QRect(400, 16, 110, 24));
        Date1->setDateTime(QDateTime(QDate(2014, 1, 1), QTime(0, 0, 0)));
        label_26 = new QLabel(tab_5);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(330, 20, 61, 16));
        rbDay = new QRadioButton(tab_5);
        rbDay->setObjectName(QStringLiteral("rbDay"));
        rbDay->setGeometry(QRect(70, 40, 71, 20));
        rbDay->setCheckable(true);
        rbDay->setChecked(false);
        rbMonth = new QRadioButton(tab_5);
        rbMonth->setObjectName(QStringLiteral("rbMonth"));
        rbMonth->setGeometry(QRect(150, 40, 71, 20));
        rbYear = new QRadioButton(tab_5);
        rbYear->setObjectName(QStringLiteral("rbYear"));
        rbYear->setGeometry(QRect(230, 40, 71, 20));
        empty = new QPushButton(tab_5);
        empty->setObjectName(QStringLiteral("empty"));
        empty->setGeometry(QRect(570, 55, 81, 32));
        display = new QPushButton(tab_5);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(340, 55, 91, 32));
        query = new QPushButton(tab_5);
        query->setObjectName(QStringLiteral("query"));
        query->setGeometry(QRect(460, 55, 81, 32));
        label_20 = new QLabel(tab_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 20, 59, 16));
        incomeList = new QTableWidget(tab_5);
        incomeList->setObjectName(QStringLiteral("incomeList"));
        incomeList->setGeometry(QRect(0, 90, 703, 287));
        tabWidget->addTab(tab_5, QString());
        pbQuit = new QPushButton(adminForm);
        pbQuit->setObjectName(QStringLiteral("pbQuit"));
        pbQuit->setGeometry(QRect(610, 420, 81, 32));

        retranslateUi(adminForm);
        QObject::connect(pbQuit, SIGNAL(clicked()), adminForm, SLOT(close()));
        QObject::connect(Add, SIGNAL(clicked()), adminForm, SLOT(setTable()));
        QObject::connect(Reset, SIGNAL(clicked()), adminForm, SLOT(removeTable()));
        QObject::connect(Finish, SIGNAL(clicked()), adminForm, SLOT(finish()));
        QObject::connect(add, SIGNAL(clicked()), adminForm, SLOT(addvip()));
        QObject::connect(reset, SIGNAL(clicked()), adminForm, SLOT(clear()));
        QObject::connect(del, SIGNAL(clicked()), adminForm, SLOT(delvip()));
        QObject::connect(save, SIGNAL(clicked()), adminForm, SLOT(save()));
        QObject::connect(ckbvipid, SIGNAL(toggled(bool)), adminForm, SLOT(queryvip()));
        QObject::connect(pbReset, SIGNAL(clicked()), adminForm, SLOT(reset()));
        QObject::connect(pbRepln, SIGNAL(clicked()), adminForm, SLOT(repln()));
        QObject::connect(isExist, SIGNAL(toggled(bool)), leISBN, SLOT(setDisabled(bool)));
        QObject::connect(cbvipid, SIGNAL(activated(QString)), adminForm, SLOT(queryvip()));
        QObject::connect(isExist, SIGNAL(toggled(bool)), adminForm, SLOT(queryISBN()));
        QObject::connect(cbISBN, SIGNAL(activated(QString)), adminForm, SLOT(queryISBN()));
        QObject::connect(ISBN, SIGNAL(activated(QString)), adminForm, SLOT(setNum()));
        QObject::connect(ckbvip, SIGNAL(toggled(bool)), cbvip, SLOT(setEnabled(bool)));
        QObject::connect(isExist, SIGNAL(toggled(bool)), cbISBN, SLOT(setEnabled(bool)));
        QObject::connect(ckbvipid, SIGNAL(toggled(bool)), cbvipid, SLOT(setEnabled(bool)));
        QObject::connect(ckbvipid, SIGNAL(toggled(bool)), add, SLOT(setDisabled(bool)));
        QObject::connect(ckbvipid, SIGNAL(toggled(bool)), del, SLOT(setEnabled(bool)));
        QObject::connect(ckbvipid, SIGNAL(toggled(bool)), save, SLOT(setEnabled(bool)));
        QObject::connect(Query, SIGNAL(clicked()), adminForm, SLOT(queryView()));
        QObject::connect(Del, SIGNAL(clicked()), adminForm, SLOT(delView()));
        QObject::connect(showAll, SIGNAL(clicked()), adminForm, SLOT(showAll()));
        QObject::connect(pbCover, SIGNAL(clicked()), adminForm, SLOT(chooseImg()));
        QObject::connect(isExist, SIGNAL(toggled(bool)), pbCover, SLOT(setDisabled(bool)));
        QObject::connect(rbDay, SIGNAL(clicked()), adminForm, SLOT(setDate()));
        QObject::connect(rbMonth, SIGNAL(clicked()), adminForm, SLOT(setDate()));
        QObject::connect(rbYear, SIGNAL(clicked()), adminForm, SLOT(setDate()));
        QObject::connect(display, SIGNAL(clicked()), adminForm, SLOT(display()));
        QObject::connect(query, SIGNAL(clicked()), adminForm, SLOT(queryIncome()));
        QObject::connect(empty, SIGNAL(clicked()), adminForm, SLOT(empty()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(adminForm);
    } // setupUi

    void retranslateUi(QWidget *adminForm)
    {
        adminForm->setWindowTitle(QApplication::translate("adminForm", "\347\263\273\347\273\237\347\256\241\347\220\206", 0));
        label_21->setText(QApplication::translate("adminForm", "ISBN:", 0));
        label_22->setText(QApplication::translate("adminForm", "\346\225\260\351\207\217\357\274\232", 0));
        Reset->setText(QApplication::translate("adminForm", "\351\207\215\347\275\256", 0));
        ckbvip->setText(QApplication::translate("adminForm", "\344\274\232\345\221\230\345\217\267", 0));
        Add->setText(QApplication::translate("adminForm", "\346\267\273\345\212\240", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("adminForm", "ISBN", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("adminForm", "\344\271\246\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("adminForm", "\344\273\267\346\240\274", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("adminForm", "\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("adminForm", "\344\274\232\345\221\230ID", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("adminForm", "\346\212\230\346\211\243", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("adminForm", "\351\207\221\351\242\235", 0));
        Finish->setText(QApplication::translate("adminForm", "\345\256\214\346\210\220", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("adminForm", "\345\233\276\344\271\246\351\224\200\345\224\256", 0));
        storage->setText(QString());
        label_10->setText(QApplication::translate("adminForm", "\344\274\232\345\221\230\346\212\230\346\211\243\357\274\232", 0));
        label_11->setText(QApplication::translate("adminForm", "\346\210\226   \346\226\260\345\242\236\357\274\232", 0));
        label_12->setText(QApplication::translate("adminForm", "\344\273\267\346\240\274\357\274\232", 0));
        label_13->setText(QApplication::translate("adminForm", "\344\271\246\345\220\215\357\274\232", 0));
        label_14->setText(QApplication::translate("adminForm", "\350\264\255\350\277\233\351\207\217\357\274\232", 0));
        leISBN->setText(QString());
        pbReset->setText(QApplication::translate("adminForm", "\351\207\215\347\275\256", 0));
        label_15->setText(QApplication::translate("adminForm", "\345\207\272\347\211\210\347\244\276\357\274\232", 0));
        label_16->setText(QApplication::translate("adminForm", "ISBN\357\274\232", 0));
        isExist->setText(QApplication::translate("adminForm", "\345\267\262\345\255\230\345\234\250", 0));
        label_17->setText(QApplication::translate("adminForm", "\345\272\223\345\255\230\351\207\217\357\274\232", 0));
        label_18->setText(QApplication::translate("adminForm", "\344\275\234\350\200\205\357\274\232", 0));
        label_19->setText(QApplication::translate("adminForm", "\345\207\272\347\211\210\346\227\245\346\234\237\357\274\232", 0));
        rbyes->setText(QApplication::translate("adminForm", "\346\230\257", 0));
        rbno->setText(QApplication::translate("adminForm", "\345\220\246", 0));
        pbRepln->setText(QApplication::translate("adminForm", "\350\264\255\350\277\233", 0));
        date->setDisplayFormat(QApplication::translate("adminForm", "yyyy/M/d", 0));
        rbhide->setText(QApplication::translate("adminForm", "\351\232\220\350\227\217", 0));
        pbCover->setText(QApplication::translate("adminForm", "\351\200\211\346\213\251\345\260\201\351\235\242\345\233\276\347\211\207...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("adminForm", "\345\233\276\344\271\246\350\264\255\350\277\233", 0));
        label_4->setText(QApplication::translate("adminForm", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", 0));
        save->setText(QApplication::translate("adminForm", "\344\277\235\345\255\230\344\277\256\346\224\271", 0));
        rbm->setText(QApplication::translate("adminForm", "\347\224\267", 0));
        reset->setText(QApplication::translate("adminForm", "\351\207\215\347\275\256", 0));
        del->setText(QApplication::translate("adminForm", "\345\210\240\351\231\244\344\274\232\345\221\230", 0));
        label_8->setText(QApplication::translate("adminForm", "\347\247\257\345\210\206\357\274\232", 0));
        add->setText(QApplication::translate("adminForm", "\346\226\260\345\242\236\344\274\232\345\221\230", 0));
        rbf->setText(QApplication::translate("adminForm", "\345\245\263", 0));
        label_3->setText(QApplication::translate("adminForm", "\345\247\223\345\220\215\357\274\232", 0));
        label_7->setText(QApplication::translate("adminForm", "Email\357\274\232", 0));
        label_2->setText(QApplication::translate("adminForm", "\344\274\232\345\221\230\344\277\241\346\201\257", 0));
        label_6->setText(QApplication::translate("adminForm", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", 0));
        label_9->setText(QApplication::translate("adminForm", "\347\272\247\345\210\253\357\274\232", 0));
        ckbvipid->setText(QApplication::translate("adminForm", "\344\274\232\345\221\230\345\217\267", 0));
        birth->setDisplayFormat(QApplication::translate("adminForm", "yyyy/M/d", 0));
        rbh->setText(QApplication::translate("adminForm", "\351\232\220\350\227\217", 0));
        label_5->setText(QApplication::translate("adminForm", "\346\200\247\345\210\253\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("adminForm", "\344\274\232\345\221\230\347\256\241\347\220\206", 0));
        date1->setDisplayFormat(QApplication::translate("adminForm", "yyyy/M/d", 0));
        date2->setDisplayFormat(QApplication::translate("adminForm", "yyyy/M/d", 0));
        label->setText(QApplication::translate("adminForm", "\344\272\244\346\230\223\346\227\245\346\234\237\357\274\232", 0));
        label_23->setText(QApplication::translate("adminForm", "\350\207\263", 0));
        label_24->setText(QApplication::translate("adminForm", "\344\272\244\346\230\223\347\261\273\345\236\213\357\274\232", 0));
        Query->setText(QApplication::translate("adminForm", "\346\237\245\350\257\242", 0));
        Del->setText(QApplication::translate("adminForm", "\346\270\205\347\251\272", 0));
        showAll->setText(QApplication::translate("adminForm", "\346\230\276\347\244\272\345\205\250\351\203\250", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("adminForm", "\344\272\244\346\230\223\350\256\260\345\275\225", 0));
        Date2->setDisplayFormat(QApplication::translate("adminForm", "yyyy/M/d", 0));
        label_25->setText(QApplication::translate("adminForm", "\350\207\263", 0));
        Date1->setDisplayFormat(QApplication::translate("adminForm", "yyyy/M/d", 0));
        label_26->setText(QApplication::translate("adminForm", "\346\237\245\350\257\242\346\227\266\351\227\264\357\274\232", 0));
        rbDay->setText(QApplication::translate("adminForm", "\346\227\245\346\224\266\345\205\245", 0));
        rbMonth->setText(QApplication::translate("adminForm", "\346\234\210\346\224\266\345\205\245", 0));
        rbYear->setText(QApplication::translate("adminForm", "\345\271\264\346\224\266\345\205\245", 0));
        empty->setText(QApplication::translate("adminForm", "\346\270\205\347\251\272", 0));
        display->setText(QApplication::translate("adminForm", "\346\230\276\347\244\272\345\205\250\351\203\250", 0));
        query->setText(QApplication::translate("adminForm", "\346\237\245\350\257\242", 0));
        label_20->setText(QApplication::translate("adminForm", "\346\237\245\350\257\242\346\226\271\345\274\217\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("adminForm", "\346\224\266\345\205\245\346\237\245\350\257\242", 0));
        pbQuit->setText(QApplication::translate("adminForm", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class adminForm: public Ui_adminForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFORM_H
