#include "searchitem.h"
#include "ui_searchitem.h"


SearchItem::SearchItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchItem)
{

    ui->setupUi(this);
    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel;
    if(database1.open())
    {
    qry.prepare("SELECT ProductDescription AS ItemName FROM items GROUP By ProductDescription");
    qry.exec();

    modal->setQuery(std::move(qry));

    ui->inventory->setModel(modal);
     ui->inventory->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    qDebug() << "\nOpening inventory good";
    }
    else
    {

        qDebug() << qry.executedQuery();
        qDebug() << qry.lastError().text();
        qDebug() << "\nfailed to open items from database";
    }
    database1.close();
}

SearchItem::~SearchItem()
{
    delete ui;
}

void SearchItem::on_addmembers_2_clicked()
{

    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel;
    QString search;
    search = ui->nameEdit->text();
    database1.open();
    qry.prepare("SELECT SUM(Quantity) AS Quantity, PriceOfProduct*SUM(Quantity) AS TotalRevenue FROM items WHERE ProductDescription = '"+search+"'");
    if(qry.exec())
    {
        modal->setQuery(std::move(qry));

        ui->output->setModel(modal);
        ui->output->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
        ui->output->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
      //  QString message = "Successfully Search";
//        ui->error->setPlaceholderText(message);
        qDebug() << "\nSEarch good";
    }


    else
    {

        QString message = "Invalid Item";
        ui->error->setPlaceholderText(message);
        qDebug() << qry.executedQuery();
        qDebug() << qry.lastError().text();
        qDebug() << "\nfailed to search";
    }
    database1.close();
}


