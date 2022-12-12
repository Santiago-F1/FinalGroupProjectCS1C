#include "addtrans.h"
#include "qsqlquery.h"
#include "ui_addtrans.h"
#include <QSqlDatabase>
#include <QDate>
#include <QSqlError>
#include "database.h"

extern QSqlDatabase database;
QString date;
QDate dateFormat;
int month;
int day;
int year;
int customerID;
double productPrice;
int quantity;
QString productDescription;

AddTrans::AddTrans(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTrans)
{
    ui->setupUi(this);
}

AddTrans::~AddTrans()
{
    delete ui;
}

void AddTrans::on_Date_textChanged()
{
    date = ui->Date->toPlainText();
    dateFormat = QDate::fromString(date,"MM/dd/yyyy");
    month = dateFormat.month();
    day = dateFormat.day();
    year = dateFormat.year();
}


void AddTrans::on_CustomerPurchased_textChanged()
{
    customerID = ui->CustomerPurchased->toPlainText().toInt();
}


void AddTrans::on_PriceOfProduct_textChanged()
{
    productPrice = ui->PriceOfProduct->toPlainText().toInt();
}


void AddTrans::on_Quantity_textChanged()
{
    quantity = ui->Quantity->toPlainText().toInt();
}


void AddTrans::on_ProductDescription_textChanged()
{
    productDescription = ui->ProductDescription->toPlainText();
}


void AddTrans::on_addItem_clicked()
{
    database.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
    QSqlQuery qry;
    if (database.open())
    {
        qDebug() << qry.prepare("INSERT INTO items (Month, Day, Year, CustomerPurchasedID, PriceOfProduct, Quantity, ProductDescription)" "VALUES(:Month, :Day, :Year, :customerID, :ROUND(productPrice,2), :quantity, :productDescription)");
        qDebug() << qry.lastError().text();
        qry.bindValue(0, month);
        qry.bindValue(1, day);
        qry.bindValue(2, year);
        qry.bindValue(3, customerID);
        qry.bindValue(4, productPrice);
        qry.bindValue(5, quantity);
        qry.bindValue(6, productDescription);

        if (qry.exec())
        {
            updateTotal(database);
            updateRebate(database);
            qry.clear();
            qDebug() << "\nDatabase worked";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qry.clear();
            qDebug() << "\nDatabase did not work";
        }
        database.close();
    }
    database.close();
}
