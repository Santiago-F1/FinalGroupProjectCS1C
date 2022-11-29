#include "rebate.h"
#include "ui_rebate.h"

Rebate::Rebate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rebate)
{
    ui->setupUi(this);
}

Rebate::~Rebate()
{
    delete ui;
}
