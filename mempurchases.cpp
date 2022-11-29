#include "mempurchases.h"
#include "ui_mempurchases.h"

MemPurchases::MemPurchases(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemPurchases)
{
    ui->setupUi(this);
}

MemPurchases::~MemPurchases()
{
    delete ui;
}
