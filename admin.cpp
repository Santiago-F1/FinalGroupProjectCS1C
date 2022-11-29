#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    QDateTime date = QDateTime::currentDateTime();
    QString formatted = date.toString("MM/dd/yyyy hh:mm");
    ui->DateTime->setText(formatted);

}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_Inventory_clicked()
{

    Inv = new Inventory(this);
    Inv->setGeometry(463,307,975, 650);
    Inv->show();
}


void Admin::on_UpdateMembers_clicked()
{
    //310 219 980 680

    upMems = new UpdateMembers(this);
    upMems->setGeometry(463,307,975, 650);
    upMems->show();
}

void Admin::on_UpdateMembers_2_clicked()
{
    upExec = new UpdateExec(this);
    upExec->setGeometry(463,307,975, 650);
    upExec->show();
}

