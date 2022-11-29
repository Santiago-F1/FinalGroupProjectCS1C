#include "memstatus.h"
#include "ui_memstatus.h"

MemStatus::MemStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemStatus)
{
    ui->setupUi(this);
}

MemStatus::~MemStatus()
{
    delete ui;
}
