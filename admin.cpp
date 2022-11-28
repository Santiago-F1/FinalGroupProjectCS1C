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
