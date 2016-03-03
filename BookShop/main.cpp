#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include "mainwindow.h"

//连接数据库
bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  //MySQL驱动
    db.setDatabaseName("BookShop");                         //数据库名
    db.setHostName("localhost");                            //数据库所在主机IP，此处数据库保存在本地
    db.setPort(3307);                                       //端口号
    db.setUserName("root");                                 //登陆用户名
    db.setPassword("teamkill");                             //登陆密码
    if(!db.open())
    {
        qDebug() << "open fail\n" << db.lastError().driverText() << "\n";
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    if(!createConnection()) return 1;                            //连接数据库
    MainWindow mw;                                               //创建主界面对象
    mw.show();                                                   //显示主界面
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit())); //信号-槽连接，最后一个窗口关闭时退出程序
    return a.exec();
}
