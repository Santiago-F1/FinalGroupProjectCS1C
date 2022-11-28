#include "loginui.h"

#include "ui_loginui.h"



loginui::loginui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginui)
{
    ui->setupUi(this);
}

loginui::~loginui()
{
    delete ui;
}

void loginui::on_pushButton_clicked()
{


    QString username = ui->usernameedit->text();
    QString password = ui->passwordedit->text();


    if(username == "storemanager" && password == "password")
    {
        //this->hide();
        QString message = " ";
        ui->textBrowser->setPlaceholderText(message);
        store = new Storemanager(this);
        store->show();



    }
    else if(username =="admin" && password == "password")
    {
          QString message = " ";    //gets rid of error message could have done it better but idk how
          ui->textBrowser->setPlaceholderText(message);
          admin = new Admin(this);
          admin->show();
    }
    else
    {
        ui->textBrowser->clear();
        QString message = "Incorrect Username or Password";
        ui->textBrowser->setPlaceholderText(message);
    }

}
