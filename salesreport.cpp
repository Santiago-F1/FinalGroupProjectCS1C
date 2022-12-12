#include "salesreport.h"
#include "ui_salesreport.h"

SalesReport::SalesReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalesReport)
{
    ui->setupUi(this);
//    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
//    database1.setDatabaseName("C:/Users/Kasim/Desktop/1c_lastProject/FinalGroupProjectCS1C/items.db");
//    QSqlQuery qry;
//    QSqlQueryModel *modal=new QSqlQueryModel;

//    if(!database1.open())
//    {
//        ui->test->setText("not open");
//    }
//    else
//    {

//   ui->test->setText("open");
//  // qry.prepare("SELECT MemberName, MemberNumber, MembershipType,RebateAmount FROM Members GROUP By MemberNumber GROUP By MembershipType");
// //----  qry.prepare("SELECT MemberName, MemberNumber, MembershipType,RebateAmount FROM Members");
// //qry.prepare("SELECT MemberName, MemberNumber, MembershipType,RebateAmount FROM Members");

//      qry.prepare("SELECT Day, ROUND(SUM(PriceOfProduct)*1.775,2) AS DailyTotal FROM items GROUP By Day");
//         if (qry.exec()){
//            // qry.;

//           ui->table->setText(" ");
//           modal->setQuery(std::move(qry));

//            ui->tableView->setModel(modal);
//       //   qry.prepare("SELECT MemberName, MemberNumber, RebateAmount FROM Members WHERE MembershipType = 'Member' GROUP By MemberNumber");
// ui->tableView->setModel(modal);
//    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
//    database1.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");
//    QSqlQuery qry;
//    QSqlQuery qry2;
//    QSqlQueryModel *modal=new QSqlQueryModel;
//    QSqlQueryModel *modal2=new QSqlQueryModel;

//    database1.open();


//        qry.prepare("SELECT MemberName, MembershipType, MemberNumber, shouldUpgrade AS Status FROM Members WHERE shouldUpgrade = 'UPGRADE'");
//        if (qry.exec())
//        {
//            modal->setQuery(std::move(qry));

//            ui->tableView->setModel(modal);
//           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

//            ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
//            ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
//            ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
//            ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

//            qDebug() << "\n GOOD DISPLAYING THING";
//        }
//        else
//        {
//            qDebug() << qry.executedQuery();
//            qDebug() << qry.lastError().text();
//            qDebug() << "\nfailed to update add/delete amount";
//        }

//        qry2.prepare("SELECT MemberName, MembershipType, MemberNumber, shouldUpgrade AS Status FROM Members WHERE shouldUpgrade = 'DOWNGRADE'");
//        if (qry2.exec())
//        {
//            modal2->setQuery(std::move(qry2));

//            ui->tableView_2->setModel(modal2);
//           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

//            ui->tableView_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
//            ui->tableView_2->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
//            ui->tableView_2->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
//            ui->tableView_2->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

//            qDebug() << "\n GOOD DISPLAYING exec in update members";
//        }
//        else
//        {
//            qDebug() << qry2.executedQuery();
//            qDebug() << qry2.lastError().text();
//            qDebug() << "\nfailed to display exec in update members ";
//        }

//   // delete modal;
//    database1.close();

}



SalesReport::~SalesReport()
{
    delete ui;
}

void SalesReport::on_pushButton_clicked()
{

    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
    QSqlQuery qry;
    QSqlQuery qry2;
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQueryModel *modal2=new QSqlQueryModel;
    QSqlQueryModel *modal3=new QSqlQueryModel;
    QString search;
    search = ui->nameEdit->text();
    database1.open();

        //SELECT Day, ROUND(SUM(PriceOfProduct)*1.0775,2) AS TotalRevenue FROM items WHERE day ='1'  total reveune
//
//    SELECT Day, MemberName, MemberNumber, ProductDescription AS Item, Quantity,
//    FROM Members JOIN
//    items
//    on CustomerPurchasedID = MemberNumber
//    WHERE day = '1'
//    SELECT COUNT(DISTINCT MemberName) as num_customers,
//           COUNT(DISTINCT CASE WHEN MembershipType = 'Executive' THEN MemberName END) as num_executive_members,
//           COUNT(dISTINCT CASE WHEN MembershipType = 'Regular' THEN MemberName END) as num_regular_members,
//           ROUND(SUM(PriceOfProduct * Quantity * (1 + .0775)),2) as total_revenue
//    FROM items
//    INNER JOIN Members ON CustomerPurchasedID = MemberNumber
//    WHERE Day = '7'
//    GROUP BY Day
        qry.prepare("SELECT Day, MemberName, ProductDescription AS Item, Quantity FROM Members JOIN items on CustomerPurchasedID = MemberNumber WHERE day = '"+search+"'");
        if (qry.exec())
        {
            modal->setQuery(std::move(qry));

            ui->tableView->setModel(modal);
           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

            ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
            ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
            ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
            ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

            qDebug() << "\n GOOD DISPLAYING SALES REPORT";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nfailed SALES REPORT";
        }

        qry2.prepare("SELECT Day, COUNT(DISTINCT CASE WHEN MembershipType = 'Executive' THEN MemberName END) as Executive_Members, ROUND(SUM(PriceOfProduct * Quantity * (1 + .0775)),2) as TotalRevenue FROM items INNER JOIN Members ON CustomerPurchasedID = MemberNumber AND MembershipType = 'Executive' WHERE Day = '"+search+"' GROUP BY Day");
        if (qry2.exec())
        {
            modal2->setQuery(std::move(qry2));

            ui->Executive->setModel(modal2);
           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

            ui->Executive->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
            ui->Executive->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
            ui->Executive->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
            qDebug() << "\n GOOD DISPLAYING exec in update members";
        }
        else
        {
            qDebug() << qry2.executedQuery();
            qDebug() << qry2.lastError().text();
            qDebug() << "\nfailed to display exec in update members ";
        }
        QSqlQuery qry3;
        qry3.prepare("SELECT Day, COUNT(DISTINCT CASE WHEN MembershipType = 'Regular' THEN MemberName END) as Regular_Members, ROUND(SUM(PriceOfProduct * Quantity * (1 + .0775)),2) as TotalRevenue FROM items INNER JOIN Members ON CustomerPurchasedID = MemberNumber AND MembershipType = 'Regular'  WHERE Day = '"+search+"' GROUP BY Day");
        if (qry3.exec())
        {
            modal3->setQuery(std::move(qry3));

            ui->Regular->setModel(modal3);
           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

            ui->Regular->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
            ui->Regular->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
            ui->Regular->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
            qDebug() << "\n GOOD DISPLAYING exec in update members";
        }
        else
        {
            qDebug() << qry3.executedQuery();
            qDebug() << qry3.lastError().text();
            qDebug() << "\nfailed to display exec in update members ";
        }
   // delete modal;
    database1.close();

}


