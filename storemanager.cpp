#include "storemanager.h"
#include "ui_storemanager.h"

Storemanager::Storemanager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Storemanager)
{
    ui->setupUi(this);
    QDateTime date = QDateTime::currentDateTime();
    QString formatted = date.toString("MM/dd/yyyy hh:mm");
    ui->DateTime->setText(formatted);
}

Storemanager::~Storemanager()
{
    delete ui;
}



void Storemanager::on_SalesReport_clicked()
{
    Sales = new SalesReport(this);
    Sales->setGeometry(463,307,975, 650);
    Sales->show();


}


void Storemanager::on_StoreProducts_clicked()
{

    Store = new StoreProducts(this);
    Store->setGeometry(463,307,975, 650);
    Store->show();
}


void Storemanager::on_SearchItem_clicked()
{
    Search = new SearchItem(this);
    Search->setGeometry(463,307,975, 650);
    Search->show();
}


void Storemanager::on_AddTrans_clicked()
{

    addTrans = new AddTrans(this);
    addTrans->setGeometry(463,307,975, 650);

    addTrans->show();

}


void Storemanager::on_addMembers_clicked()
{

    addMems = new AddMembers(this);
    addMems->setGeometry(463,307,975, 650);
    addMems->show();
}


void Storemanager::on_MemPurchases_clicked()
{
    memP = new MemPurchases(this);
    memP->setGeometry(463,307,975, 650);
    memP->show();

}


void Storemanager::on_Rebate_clicked()
{

    rebate = new Rebate(this);
    rebate->setGeometry(463,307,975, 650);
    rebate->show();
}


void Storemanager::on_MemStatus_clicked()
{
    memStatus = new MemStatus(this);
    memStatus->setGeometry(463,307,975, 650);
    memStatus->show();

}

