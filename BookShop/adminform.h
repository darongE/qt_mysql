#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QWidget>
#include <QSqlTableModel>
#include <QLabel>

namespace Ui {
class adminForm;
}

class adminForm : public QWidget
{
    Q_OBJECT

public:
    explicit adminForm(QWidget *parent = 0);
    ~adminForm();

private:
    Ui::adminForm *ui;
    void refreshvip();
    void refreshISBN();
    QSqlTableModel *tradeModel;
    QLabel *label;
    QString fileName;

private slots:
    //图书销售
    void setNum();
    void setTable();
    void removeTable();
    void finish();
    //图书购进
    void reset();
    void repln();
    void queryISBN();
    void chooseImg();
    //会员管理
    void save();
    void clear();
    void delvip();
    void addvip();
    void queryvip();
    //交易记录
    void queryView();
    void delView();
    void showAll();
    //收入查询
    void setDate();
    void queryIncome();
    void empty();
    void display();
};

#endif // ADMINFORM_H
