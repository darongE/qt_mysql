#include <QtWidgets>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "dbookinfo.h"
#include "ui_dbookinfo.h"

DBookInfo::DBookInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBookInfo)
{
    ui->setupUi(this);
    bookInfoModel = new QSqlTableModel(this);
    bookInfoModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->BookList->setModel(bookInfoModel);

    bookInfoModel->setTable("Book");
    bookInfoModel->select();
    ISBNBind();
}

DBookInfo::~DBookInfo()
{
    delete ui;
}

void DBookInfo::showAll()
{
    bookInfoModel->setFilter("1=1");
    bookInfoModel->select();
}

//根据条件过滤查询图书信息
void DBookInfo::query()
{
    QString select;
    select = "1=1";                     //此设置没有实际意义，保证过滤语句中的“and”有效
    if(ui->cbByName->isChecked())       //按书名查找
        select += " and Name like '%"+ ui->leName->text() +"%'";     //实现按书名模糊匹配
    if(ui->cbByPress->isChecked())      //按出版社查找
        select += " and Press like '%"+ ui->lePress->text() +"%'";   //实现按出版社模糊匹配
    if(ui->cbByAuthor->isChecked())     //按作者查找
        select += " and Author like '%"+ ui->leAuthor->text() +"%'"; //实现按作者模糊匹配
    bookInfoModel->setFilter(select);   //根据select语句进行过滤器设置
    bookInfoModel->select();            //过滤信息，同时更新视图
}

void DBookInfo::reset()
{
    ui->leName->setText("");
    ui->lePress->setText("");
    ui->leAuthor->setText("");
    ui->cbByName->setChecked(0);
    ui->cbByPress->setChecked(0);
    ui->cbByAuthor->setChecked(0);
}

void DBookInfo::queryByISBN()
{
    bookInfoModel->setFilter(QObject::tr("ISBN = '%1'").arg(ui->cbISBNList->currentText()));
    bookInfoModel->select();
}

void DBookInfo::setEnable()
{
    if(ui->cbByName->isChecked()) ui->leName->setEnabled(true);
    else ui->leName->setEnabled(false);
    if(ui->cbByPress->isChecked()) ui->lePress->setEnabled(true);
    else ui->lePress->setEnabled(false);
    if(ui->cbByAuthor->isChecked()) ui->leAuthor->setEnabled(true);
    else ui->leAuthor->setEnabled(false);
}

void DBookInfo::ISBNBind()
{
    ui->cbISBNList->clear();
    QSqlQuery query;
    query.exec("select ISBN from Book");
    while(query.next())
    {
        ui->cbISBNList->insertItem(0,query.value(0).toString());
    }
}
