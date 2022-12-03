#include "updateexec.h"
#include "ui_updateexec.h"

UpdateExec::UpdateExec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateExec)
{
    ui->setupUi(this);
}

UpdateExec::~UpdateExec()
{
    delete ui;
}
