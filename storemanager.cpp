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


