#include "addtrans.h"
#include "ui_addtrans.h"

AddTrans::AddTrans(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTrans)
{
    ui->setupUi(this);
}

AddTrans::~AddTrans()
{
    delete ui;
}
