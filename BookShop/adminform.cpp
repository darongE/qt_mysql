#include <QtWidgets>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include "adminform.h"
#include "ui_adminform.h"

adminForm::adminForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminForm)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("select id from VIP order by id");
    while(query.next())
    {
        ui->cbvip->insertItem(0,query.value(0).toString());     //图书销售界面
        ui->cbvipid->insertItem(0,query.value(0).toString());   //会员管理界面
    }
    query.exec("select ISBN from Book");
    while(query.next())
    {
        ui->ISBN->insertItem(0,query.value(0).toString());      //图书销售界面
        ui->cbISBN->insertItem(0,query.value(0).toString());    //图书购进界面
    }
    ui->cbItem->insertItem(0,"售书");
    ui->cbItem->insertItem(1,"购进");
    ui->rbhide->setVisible(0);
    ui->rbh->setVisible(0);
    ui->sbRepln->clear();
    ui->sbPrice->clear();

    tradeModel = new QSqlTableModel(this);
    tradeModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tradeList->setModel(tradeModel);

    label = new QLabel;
    ui->scrollArea->setWidget(label);
    //label->setScaledContents(true);

    ui->rbDay->setChecked(1);
    setDate();
}

adminForm::~adminForm()
{
    delete ui;
}

//图书销售
void adminForm::setNum()
{
    QSqlQuery query;
    query.exec("select Storage from Book where ISBN = '" + ui->ISBN->currentText() + "'");
    query.next();
    int storage = query.value(0).toInt();
    ui->Num->setMaximum(storage);
}

void adminForm::setTable()
{
    QSqlQuery query;
    query.exec("select * from Book where ISBN = '" + ui->ISBN->currentText() + "'");
    query.next();
    int i = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));  //ISBN
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));  //书名
    ui->tableWidget->setItem(i,3,new QTableWidgetItem(ui->Num->text()));            //数量
    float price,total,discount=1,discnt = 1;
    QString Price,Discount,Total;
    int isDiscnt = query.value(6).toInt();
    price = query.value(5).toFloat();
    Price = Price.setNum(price,'f',1);
    ui->tableWidget->setItem(i,2,new QTableWidgetItem(Price));  //价格
    if(ui->ckbvip->isChecked())
    {
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(ui->cbvip->currentText()));   //会员ID
        query.exec("select Discount from Discount join VIP where Discount.Level = VIP.Level "
                    "and VIP.id = " + ui->cbvip->currentText());
        query.next();
        discnt = query.value(0).toFloat();
    }
    else ui->tableWidget->setItem(i,4,new QTableWidgetItem(""));
    int num = ui->Num->text().toInt();
    if(isDiscnt) discount *= discnt;
    total = num * price * discount;
    Discount = Discount.setNum(discount,'f',2);
    Total = Total.setNum(total,'f',1);
    ui->tableWidget->setItem(i,5,new QTableWidgetItem(Discount));
    ui->tableWidget->setItem(i,6,new QTableWidgetItem(Total));
}

void adminForm::removeTable()
{
    ui->tableWidget->setRowCount(0);
}

void adminForm::finish()
{
    QDate date = QDate::currentDate();
    bool flag = true;
    QSqlQuery query;
    QString vipID, BookISBN, Num, Discount, Sum, insertData;
    int storage,score,level;
    for(int i=0; i < ui->tableWidget->rowCount(); i++)
    {
        Num = ui->tableWidget->item(i,3)->text();
        if(Num.toInt() == 0) continue;
        BookISBN = ui->tableWidget->item(i,0)->text();
        vipID = ui->tableWidget->item(i,4)->text();
        if(vipID == "") vipID = "NULL";
        Discount = ui->tableWidget->item(i,5)->text();
        Sum = ui->tableWidget->item(i,6)->text();
        insertData = "insert into Sell(vipID,BookISBN,Number,Discount,Sum,Time) "
                     "values("+vipID +",'"+BookISBN +"',"+Num +","+Discount +","
                     +Sum +",str_to_date('"+tr("%1").arg(date.year()) +"-"+tr("%1").arg(date.month())
                     +"-"+tr("%1").arg(date.day()) +"','%Y-%m-%d'))";
        if(query.exec(insertData))
        {
            query.exec("select Storage from Book where ISBN = '" + BookISBN +"'");
            if(query.next())
            {
                storage = query.value(0).toInt();
                storage -= Num.toInt();
                query.exec("update Book set Storage="+tr("%1").arg(storage) +" where ISBN='"+BookISBN +"'");
            }
            if(ui->ckbvip->isChecked())
            {
                query.exec("select Score,Level from VIP where id = " + vipID);
                if(query.next())
                {
                    score = query.value(0).toInt();
                    level = query.value(1).toInt();
                    score += 5 * Num.toInt();
                    if(score >= 100 && level < 5)
                    {
                        level ++;
                        score -= 100;
                    }
                    query.exec("update VIP set Score="+tr("%1").arg(score) +",Level="+tr("%1").arg(level)
                               +" where id="+vipID);
                }
            }
        }
        else
        {
            flag = false;
            QMessageBox::about(this,"提示",tr("销售图书："+BookISBN.toUtf8() +"失败"));
        }
    }
    if(flag) QMessageBox::about(this,"提示",tr("销售图书成功"));
}

//图书购进
void adminForm::chooseImg()
{
    fileName = QFileDialog::getOpenFileName(this, tr("选择图片"),QApplication::applicationDirPath());
    if(!fileName.isEmpty())
    {
        QImage cover(fileName);
        if(cover.isNull())
        {
            QMessageBox::information(this,tr("查看图片"),tr("无法打开 %1").arg(fileName));
            fileName = "";
            return;
        }
        label->setPixmap(QPixmap::fromImage(cover.scaled(ui->scrollArea->size(),Qt::KeepAspectRatio)));
    }
}

void adminForm::reset()
{
    ui->isExist->setChecked(0);
    ui->leISBN->clear();
    ui->leBname->clear();
    ui->leAuthor->clear();
    ui->lePress->clear();
    ui->sbPrice->clear();
    ui->storage->clear();
    ui->sbRepln->clear();
    ui->rbhide->setChecked(1);
    QDate date(2000,1,1);
    ui->date->setDate(date);
    fileName = "";
    label->clear();
}

void adminForm::repln()
{
    QSqlQuery query;
    QString BookISBN;
    QDate date = QDate::currentDate();
    bool flag = false;
    int repln;
    repln = ui->sbRepln->value();
    if(ui->isExist->isChecked())
    {
        int storage = ui->storage->text().toInt();
        storage += repln;
        BookISBN = ui->cbISBN->currentText();
        QString update;
        update = "update Book set Storage = " + tr("%1").arg(storage)
                 + " where ISBN='"+ BookISBN + "'";
        if(query.exec(update))
        {
            flag = true;
            QMessageBox::about(this,"提示",tr("购进图书成功"));
            queryISBN();
        }
        else
        {
            QMessageBox::about(this,"提示",tr("购进图书失败"));
        }
    }
    else
    {
        QString insert, BName;
        if(ui->leISBN->text() == "") BookISBN = "NULL";
        else BookISBN = "'"+ ui->leISBN->text() +"'";
        if(ui->leBname->text() == "") BName = "NULL";
        else BName = "'"+ ui->leBname->text() +"'";
        int isDiscnt = 0, hasCov = 0;
        if(ui->rbyes->isChecked()) isDiscnt = 1;
        if(fileName!="" && ui->leISBN->text()!="")
        {
            QString imgName;
            imgName = QApplication::applicationDirPath() +"/covers/"+ui->leISBN->text() +fileName.right(4);
            QFile::copy(fileName,imgName);
            hasCov = 1;
        }
        insert = "insert into Book(ISBN,Name, Author, Press, PublishDate, Price, isDiscount, Storage, hasCover)"
                 " values("+BookISBN +","+BName +",'"+ui->leAuthor->text() +"','"
                 +ui->lePress->text() +"',str_to_date('"+ ui->date->text() +"','%Y/%m/%d'),"
                 +tr("%1").arg(ui->sbPrice->value()) +","+tr("%1").arg(isDiscnt) +","+tr("%1").arg(repln)
                 +","+tr("%1").arg(hasCov) + ")";
        if(query.exec(insert))
        {
            flag = true;
            QMessageBox::about(this,"提示",tr("购进图书成功"));
            refreshISBN();
        }
        else
        {
            QMessageBox::about(this,"提示",tr("购进图书失败"));
        }
    }
    QString bookISBN;
    if(ui->isExist->isChecked()) bookISBN = "'"+ BookISBN +"'";
    else bookISBN = BookISBN;
    if(flag) query.exec("insert into Replenish(BookISBN,Number,Time) values("+bookISBN +","+tr("%1").arg(repln)
                        +",str_to_date('"+tr("%1").arg(date.year()) +"-"+tr("%1").arg(date.month())
                        +"-"+tr("%1").arg(date.day()) +"','%Y-%m-%d'))");
}

void adminForm::refreshISBN()
{
    QSqlQuery query;
    query.exec("select ISBN from Book");
    ui->cbISBN->clear();
    ui->ISBN->clear();
    while(query.next()){
        ui->cbISBN->insertItem(0,query.value(0).toString());
        ui->ISBN->insertItem(0,query.value(0).toString());
    }
    queryISBN();
}

void adminForm::queryISBN()
{
    if(ui->isExist->isChecked())
    {
        QSqlQuery query;
        QString select;
        select = "select * from Book where ISBN = '" + ui->cbISBN->currentText() + "'";
        query.exec(select);
        query.next();
        QString name, author, press, storage;
        QDate pdate;
        float price;
        int isDiscnt, hasCov;
        name = query.value(1).toString();
        ui->leBname->setText(name);
        author = query.value(2).toString();
        ui->leAuthor->setText(author);
        press = query.value(3).toString();
        ui->lePress->setText(press);
        pdate = query.value(4).toDate();
        ui->date->setDate(pdate);
        price = query.value(5).toFloat();
        ui->sbPrice->setValue(price);
        isDiscnt = query.value(6).toInt();
        if(isDiscnt == 1) ui->rbyes->setChecked(true);
        else if(isDiscnt == 0) ui->rbno->setChecked(true);
        storage = query.value(7).toString();
        ui->storage->setText(storage);
        ui->sbRepln->clear();
        hasCov = query.value(8).toInt();
        if(hasCov == 1)
        {
            QString imgName = QApplication::applicationDirPath()+"/covers/" + ui->cbISBN->currentText() +fileName.right(4);
            QImage cover(imgName);
            label->setPixmap(QPixmap::fromImage(cover.scaled(ui->scrollArea->size(),Qt::KeepAspectRatio)));
        }
        else label->setText("暂无封面");
    }
    else reset();
}

//会员管理
void adminForm::queryvip()
{
    if(ui->ckbvipid->isChecked())
    {
        QSqlQuery query;
        QString selectStr;
        selectStr = "select * from VIP where id = " + ui->cbvipid->currentText();
        query.exec(selectStr);
        query.next();
        QString name, sex, phone, email;
        QDate birth;
        int score, level;
        name = query.value(1).toString();
        ui->leName->setText(name);
        sex = query.value(2).toString();
        if(sex == "男") ui->rbm->setChecked(true);
        else if(sex == "女") ui->rbf->setChecked(true);
        else ui->rbh->setChecked(true);
        birth = query.value(3).toDate();
        ui->birth->setDate(birth);
        phone = query.value(4).toString();
        ui->lePhone->setText(phone);
        email = query.value(5).toString();
        ui->leEmail->setText(email);
        score = query.value(6).toInt();
        ui->sbScore->setValue(score);
        level = query.value(7).toInt();
        ui->sbLevel->setValue(level);
    }
    else clear();
}

void adminForm::save()
{
    QSqlQuery query;
    QString updateStr, id, sex;
    id = ui->cbvipid->currentText();
    if(ui->rbm->isChecked()) sex = "男";
    else if(ui->rbf->isChecked()) sex = "女";
    updateStr = "update VIP set Name ='"+ui->leName->text() +"',Sex='"+sex +"',Birthday=str_to_date('"
                + ui->birth->text() +"','%Y/%m/%d'),Telephone='"+ ui->lePhone->text()
                +"',Email='"+ui->leEmail->text() +"',Score="+ tr("%1").arg(ui->sbScore->value())
                +",Level="+tr("%1").arg(ui->sbLevel->value()) +" where id = " + id;
    if(query.exec(updateStr))
    {
        QMessageBox::about(this,"提示",tr("保存成功"));
        queryvip();
    }
    else
    {
        QMessageBox::about(this,"提示",tr("保存失败"));
    }
}

void adminForm::addvip()
{
    QSqlQuery query;
    QString insertStr, Name, sex;
    if(ui->rbm->isChecked()) sex = "男";
    else if(ui->rbf->isChecked()) sex = "女";
    if(ui->leName->text() == "") Name = "NULL";
    else Name = "'" + ui->leName->text() +"'";
    insertStr = "insert into VIP(Name, Sex, Birthday, Telephone, Email, Score, Level) "
                "values("+Name +",'"+sex +"',str_to_date('"+ ui->birth->text() +"','%Y/%m/%d'),'"
                +ui->lePhone->text() +"','"+ui->leEmail->text() +"',"
                +tr("%1").arg(ui->sbScore->value()) +","+tr("%1").arg(ui->sbLevel->value()) +")";
    if(query.exec(insertStr))
    {
        QMessageBox::about(this,"提示",tr("添加成功"));
        refreshvip();
    }
    else
    {
        QMessageBox::about(this,"提示",tr("添加失败"));
    }
}

void adminForm::delvip()
{
    QSqlQuery query;
    QString deleteStr;
    deleteStr = "delete from VIP where id = " + ui->cbvipid->currentText();
    if(query.exec(deleteStr))
    {
        QMessageBox::about(this,"提示",tr("删除成功"));
        refreshvip();
    }
    else
    {
        QMessageBox::about(this,"提示",tr("删除失败"));
    }
}

void adminForm::refreshvip()
{
    QSqlQuery query;
    query.exec("select id from VIP order by id");
    ui->cbvipid->clear();
    ui->cbvip->clear();
    while(query.next())
    {
        ui->cbvipid->insertItem(0,query.value(0).toString());
        ui->cbvip->insertItem(0,query.value(0).toString());
    }
    queryvip();
}

void adminForm::clear()
{
    ui->ckbvipid->setChecked(0);
    ui->leName->clear();
    ui->rbh->setChecked(1);
    ui->lePhone->clear();
    ui->leEmail->clear();
    ui->sbScore->setValue(0);
    ui->sbLevel->setValue(1);
    QDate date(1980,1,1);
    ui->birth->setDate(date);
}

//交易记录
void adminForm::queryView()
{
    if(ui->cbItem->currentIndex() == 0) tradeModel->setTable("Sell");
    else tradeModel->setTable("Replenish");
    QString select;
    QDate date1,date2;
    date1 = ui->date1->date();
    date2 = ui->date2->date();
    select = "Time >= str_to_date('"+tr("%1").arg(date1.year()) +"-"+tr("%1").arg(date1.month())
            +"-"+tr("%1").arg(date1.day()) +"','%Y-%m-%d') and Time <= str_to_date('"
            +tr("%1").arg(date2.year()) +"-"+tr("%1").arg(date2.month()) +"-"+tr("%1").arg(date2.day())
            +"','%Y-%m-%d')";
    tradeModel->setFilter(select);
    tradeModel->select();
}

void adminForm::delView()
{
    tradeModel->setFilter("1<1");
    tradeModel->select();
}

void adminForm::showAll()
{
    if(ui->cbItem->currentIndex() == 0) tradeModel->setTable("Sell");
    else tradeModel->setTable("Replenish");
    tradeModel->setFilter("1=1");
    tradeModel->select();
}

//收入查询
void adminForm::setDate()
{
    empty();
    QStringList header;
    if(ui->rbDay->isChecked())
    {
        ui->Date1->setDisplayFormat("yyyy/M/d");
        ui->Date2->setDisplayFormat("yyyy/M/d");
        header<<"Year"<<"Month"<<"Day"<<"Income";
        ui->incomeList->setColumnCount(4);
    }
    else if(ui->rbMonth->isChecked())
    {
        ui->Date1->setDisplayFormat("yyyy/M");
        ui->Date2->setDisplayFormat("yyyy/M");
        header<<"Year"<<"Month"<<"Income";
        ui->incomeList->setColumnCount(3);
    }
    else{
        ui->Date1->setDisplayFormat("yyyy");
        ui->Date2->setDisplayFormat("yyyy");
        header<<"Year"<<"Income";
        ui->incomeList->setColumnCount(2);
    }

    ui->incomeList->setHorizontalHeaderLabels(header);
}

void adminForm::queryIncome()
{
    empty();
    QSqlQuery query;
    int i, cols;
    float income;
    QString select,Income;
    QDate date1,date2;
    date1 = ui->Date1->date();
    date2 = ui->Date2->date();
    if(ui->rbDay->isChecked())
    {
        select = "select * from daily_revenue where str_to_date(concat(Year,'-',Month,'-',Day),'%Y-%m-%d') >= str_to_date('"
                +tr("%1").arg(date1.year()) +"-"+tr("%1").arg(date1.month()) +"-"+tr("%1").arg(date1.day())
                +"','%Y-%m-%d') and str_to_date(concat(Year,'-',Month,'-',Day),'%Y-%m-%d') <= str_to_date('"
                +tr("%1").arg(date2.year()) +"-"+tr("%1").arg(date2.month()) +"-"+tr("%1").arg(date2.day())
                +"','%Y-%m-%d')";
        cols = 4;
    }
    else if(ui->rbMonth->isChecked())
    {
        select = "select Year,Month,Sum(Income) from daily_revenue group by str_to_date(concat(Year,'-',Month),'%Y-%m') having str_to_date(concat(Year,'-',Month),'%Y-%m') >= str_to_date('"
                +tr("%1").arg(date1.year()) +"-"+tr("%1").arg(date1.month())
                +"','%Y-%m') and str_to_date(concat(Year,'-',Month),'%Y-%m') <= str_to_date('"
                +tr("%1").arg(date2.year()) +"-"+tr("%1").arg(date2.month()) +"','%Y-%m')";
        cols = 3;
    }
    else
    {
        select = "select Year,Sum(Income) from daily_revenue group by str_to_date(concat(Year,''),'%Y') having str_to_date(concat(Year,''),'%Y') >= str_to_date('"
                +tr("%1").arg(date1.year()) +"','%Y') and str_to_date(concat(Year,''),'%Y') <= str_to_date('"
                +tr("%1").arg(date2.year()) +"','%Y')";
        cols = 2;
    }
    query.exec(select);
    while(query.next())
    {
        i = ui->incomeList->rowCount();
        ui->incomeList->insertRow(i);
        for(int j=0; j<cols-1; j++)
            ui->incomeList->setItem(i,j,new QTableWidgetItem(query.value(j).toString()));
        income = query.value(cols-1).toFloat();
        Income = Income.setNum(income,'f',1);
        ui->incomeList->setItem(i,cols-1,new QTableWidgetItem(Income));
    }
}

void adminForm::empty()
{
    ui->incomeList->setRowCount(0);
}

void adminForm::display()
{
    empty();
    QSqlQuery query;
    int i, cols;
    float income;
    QString select,Income;
    QDate date1,date2;
    date1 = ui->Date1->date();
    date2 = ui->Date2->date();
    if(ui->rbDay->isChecked())
    {
        select = "select * from daily_revenue";
        cols = 4;
    }
    else if(ui->rbMonth->isChecked())
    {
        select = "select Year,Month,Sum(Income) from daily_revenue group by str_to_date(concat(Year,'-',Month),'%Y-%m')";
        cols = 3;
    }
    else
    {
        select = "select Year,Sum(Income) from daily_revenue group by str_to_date(concat(Year,''),'%Y')";
        cols = 2;
    }
    query.exec(select);
    while(query.next())
    {
        i = ui->incomeList->rowCount();
        ui->incomeList->insertRow(i);
        for(int j=0; j<cols-1; j++)
            ui->incomeList->setItem(i,j,new QTableWidgetItem(query.value(j).toString()));
        income = query.value(cols-1).toFloat();
        Income = Income.setNum(income,'f',1);
        ui->incomeList->setItem(i,cols-1,new QTableWidgetItem(Income));
    }
}
