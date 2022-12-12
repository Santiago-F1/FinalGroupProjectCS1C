#include "memstatus.h"
#include "ui_memstatus.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDate>
QString dateString;
QString Month;

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

void MemStatus::on_inputDate_textChanged()
{
    Month = ui->inputDate->toPlainText();
}


void MemStatus::on_pushButton_clicked()
{
    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel;

    if(database1.open())
    {

        qry.prepare("SELECT MemberName, MemberNumber, MembershipType, renewAmount FROM Members WHERE expirationMonth = '"+Month+"'");

        if (qry.exec())
        {
            modal->setQuery(std::move(qry));

            ui->membership->setModel(modal);
           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

            ui->membership->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
            ui->membership->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
            ui->membership->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
            ui->membership->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

            qDebug() << "\nMembershipStatus Amount successful";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nfailed to update MembershipStatus";
        }
    }
   // delete modal;
    database1.close();
}
