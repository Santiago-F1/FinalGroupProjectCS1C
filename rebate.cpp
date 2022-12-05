#include "rebate.h"
#include "qsqlerror.h"
#include "ui_rebate.h"
#include<QSqlQueryModel>
#include<QSqlQuery>



Rebate::Rebate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rebate)
{
    ui->setupUi(this);

    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel;

    if(database1.open())
    {

        qry.prepare("SELECT MemberName, MemberNumber, RebateAmount FROM Members WHERE MembershipType = 'Executive' GROUP By MemberNumber");
        if (qry.exec())
        {
            modal->setQuery(std::move(qry));

            ui->tableView->setModel(modal);
           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");
            ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
            ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
            ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);


            qDebug() << "\nUpdating Rebate Amount successful";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nfailed to update rebate amount";
        }
    }
   // delete modal;
    database1.close();

}

Rebate::~Rebate()
{
    delete ui;
}


//leave this or it breaks idk why
void Rebate::on_tableView_activated(const QModelIndex &index)
{


//    QSqlQueryModel modal;
//    QSqlQuery qry;
//    if(database.open())
//    {

//        qry.prepare("SELECT MemberName, MemberNumber, RebateAmount FROM Members WHERE MembershipType = 'Executive' GROUP By MemberNumber");
//        if (qry.exec())
//        {
//            modal.setQuery(std::move(qry));
//        }
//        else
//        {
//            qDebug() << qry.executedQuery();
//            qDebug() << qry.lastError().text();
//            qDebug() << "\nFailed to update member amount total";
//        }
//    }
//    database.close();
}/**/

