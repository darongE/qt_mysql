#ifndef DBOOKINFO_H
#define DBOOKINFO_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class DBookInfo;
}

class DBookInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DBookInfo(QWidget *parent = 0);
    ~DBookInfo();

private slots:
    void showAll();
    void query();
    void reset();
    void queryByISBN();
    void setEnable();

private:
    Ui::DBookInfo *ui;
    QSqlTableModel *bookInfoModel;
    void ISBNBind();
};

#endif // DBOOKINFO_H
