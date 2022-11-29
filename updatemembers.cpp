#include "updatemembers.h"
#include "ui_updatemembers.h"

UpdateMembers::UpdateMembers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateMembers)
{
    ui->setupUi(this);

}
//UpdateMembers::setGeometry(int x, int y, int w, int h)
//{

//}

UpdateMembers::~UpdateMembers()
{
    delete ui;
}
