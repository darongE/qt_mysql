#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QDialog>

namespace Ui {
class loginwin;
}

class loginwin : public QDialog
{
    Q_OBJECT

public:
    explicit loginwin(QWidget *parent = 0);
    ~loginwin();

private:
    Ui::loginwin *ui;

private slots:
    void login();
};

#endif // LOGINWIN_H
