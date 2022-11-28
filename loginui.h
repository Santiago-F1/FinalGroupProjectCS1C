#ifndef LOGINUI_H
#define LOGINUI_H
#include"admin.h"
#include"storemanager.h"

#include <QDialog>

namespace Ui {
class loginui;
}

class loginui : public QDialog
{
    Q_OBJECT

public:
    explicit loginui(QWidget *parent = nullptr);
    ~loginui();

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginui *ui;
    Storemanager *store;
    Admin *admin;

};

#endif // LOGINUI_H
