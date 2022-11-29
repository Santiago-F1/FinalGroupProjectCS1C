#include "storeproducts.h"
#include "ui_storeproducts.h"

StoreProducts::StoreProducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreProducts)
{
    ui->setupUi(this);
}

StoreProducts::~StoreProducts()
{
    delete ui;
}
