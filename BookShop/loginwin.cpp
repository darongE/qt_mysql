#include <QSqlQuery>
#include <QMessageBox>
#include "loginwin.h"
#include "ui_loginwin.h"
#include "adminform.h"

loginwin::loginwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginwin)
{
    ui->setupUi(this);
    ui->pwd->setEchoMode(QLineEdit::Password);
    ui->user->setText("");
}

loginwin::~loginwin()
{
    delete ui;
}

void loginwin::login()
{
    bool flag = false;      //用户登陆成功标志

    QString user = ui->user->text().trimmed();  //获取输入的用户名
    QString pwd = ui->pwd->text().trimmed();    //获取输入的密码
    if(user.isEmpty()) QMessageBox::about(this,"提示","请输入用户名！");    //输入用户名为空
    else if(pwd.isEmpty()) QMessageBox::about(this,"提示","请输入密码！");  //输入密码为空
    else
    {
        QSqlQuery query;
        query.exec("select * from Administer");  //查询Administer表
        while(query.next())
        {
            if(user == query.value(0).toString() && pwd == query.value(1).toString())   //用户名、密码匹配
            {
                flag = true;                        //用户登陆成功
                adminForm *af = new adminForm();    //创建管理员界面
                af->show();                         //打开管理员界面
                this->close();                      //关闭登陆界面
                return;
            }
        }
        if(!flag) QMessageBox::about(this,"提示","用户名或密码错误！");    //登陆失败
    }
}
