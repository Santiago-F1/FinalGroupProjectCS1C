#include "salesreport.h"
#include "ui_salesreport.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
SalesReport::SalesReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalesReport)
{
    ui->setupUi(this);
    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/Kasim/Desktop/1c_lastProject/FinalGroupProjectCS1C/items.db");
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel;

    if(!database1.open())
    {
        ui->test->setText("not open");
    }
else
 {

   ui->test->setText("open");
  // qry.prepare("SELECT MemberName, MemberNumber, MembershipType,RebateAmount FROM Members GROUP By MemberNumber GROUP By MembershipType");
 //----  qry.prepare("SELECT MemberName, MemberNumber, MembershipType,RebateAmount FROM Members");
 //qry.prepare("SELECT MemberName, MemberNumber, MembershipType,RebateAmount FROM Members");

      qry.prepare("SELECT Day, ROUND(SUM(PriceOfProduct)*1.775,2) AS DailyTotal FROM items GROUP By Day");
         if (qry.exec()){
            // qry.;

           ui->test->setText(" ");
           modal->setQuery(std::move(qry));

            ui->tableView->setModel(modal);
       //   qry.prepare("SELECT MemberName, MemberNumber, RebateAmount FROM Members WHERE MembershipType = 'Member' GROUP By MemberNumber");
 ui->tableView->setModel(modal);

         }
}
}

SalesReport::~SalesReport()
{
    delete ui;
}
