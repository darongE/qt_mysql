#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwin.h"
#include "dbookinfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login()
{
    loginwin *lgw = new loginwin();
    lgw->show();
}

void MainWindow::info()
{
    DBookInfo *dbi = new DBookInfo();
    dbi->show();
}
