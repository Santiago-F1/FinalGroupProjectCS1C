//#include "mempurchases.h"
//#include "mempurchases.h"

//MemPurchases::MemPurchases(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::MemPurchases)
//{
//    ui->setupUi(this);
//    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
//    database1.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
//    QSqlQuery qry;
//    QSqlQueryModel *modal=new QSqlQueryModel;
//    if(database1.open())
//    {
//    qry.prepare("SELECT MemberName, MemberNumber, ROUND(TotalAmountSpent*1.0775,2) AS TotalWithTax FROM Members WHERE TotalAmountSpent != '0' ORDER BY MemberNumber");
//    qry.exec();

//    modal->setQuery(std::move(qry));

//    ui->inventory->setModel(modal);
//    ui->inventory->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
//    ui->inventory->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
//    qDebug() << "\nOpening inventory good";
//    }
//    else
//    {

//        qDebug() << qry.executedQuery();
//        qDebug() << qry.lastError().text();
//        qDebug() << "\nfailed to open items from database";
//    }

//    QSqlQuery qry2;
//    QSqlQueryModel *modal2=new QSqlQueryModel;
//    if(database1.open())
//    {
//    qry2.prepare("SELECT ROUND(SUM(TotalAmountSpent)*1.0775,2) AS GrandTotal FROM Members");
//    qry2.exec();

//    modal2->setQuery(std::move(qry2));

//    ui->inventory_2->setModel(modal2);
//    ui->inventory_2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
//    ui->inventory_2->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
//    qDebug() << "\nOpening inventory good";
//    }
//    else
//    {

//        qDebug() << qry2.executedQuery();
//        qDebug() << qry2.lastError().text();
//        qDebug() << "\nfailed to open items from database";
//    }








//    database1.close();
//}



//void MemPurchases::on_pushButton_clicked()
//{
//    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
//    database1.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
//    QSqlQuery qry;
//    QSqlQueryModel *modal=new QSqlQueryModel;
//    QString search;
//    search = ui->nameEdit->text();
//    database1.open();

//    qry.prepare("SELECT MemberName, MemberNumber, ROUND(TotalAmountSpent*1.0775,2) AS TotalWithTax FROM Members WHERE MemberName = '"+search+"' OR MemberNumber = '"+search+"'");
//    if(qry.exec())
//    {
//        modal->setQuery(std::move(qry));

//        ui->output->setModel(modal);
//        ui->output->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
//        ui->output->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
//        ui->output->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
//      //  QString message = "Successfully Search";
////        ui->error->setPlaceholderText(message);
//        qDebug() << "\nwork it worky yay";
//    }


//    else
//    {

//        QString message = "Invalid Item";
//        ui->error->setPlaceholderText(message);
//        qDebug() << qry.executedQuery();
//        qDebug() << qry.lastError().text();
//        qDebug() << "\nu aboslute failure";
//    }
//    database1.close();
//}

//MemPurchases::~MemPurchases()
//{
//    delete ui;
//}

