#ifndef ADMIN_H
#define ADMIN_H
#include"inventory.h"
#include"updatemembers.h"
#include"updateexec.h"
#include <QMainWindow>
#include<QDateTime>
namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_Inventory_clicked();

    void on_UpdateMembers_clicked();

    void on_UpdateMembers_2_clicked();

private:
    Ui::Admin *ui;
    Inventory *Inv;
    UpdateMembers *upMems;
    UpdateExec *upExec;

};

#endif // ADMIN_H
