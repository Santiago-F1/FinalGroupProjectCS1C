#include "salesreport.h"
#include "ui_salesreport.h"

SalesReport::SalesReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalesReport)
{
    ui->setupUi(this);
}

SalesReport::~SalesReport()
{
    delete ui;
}
