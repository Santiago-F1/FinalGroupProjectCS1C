#include "inventory.h"
#include "qsqlquery.h"
#include "ui_inventory.h"
#include <QSqlDatabase>
#include <QDate>
#include <QSqlError>


extern QSqlDatabase database;
QString originalDate;
QDate originalDateFormat;
int originalMonth;
int originalDay;
int originalYear;
int originalCustomerID;
double originalProductPrice;
int originalQuantity;
QString originalProductDescription;

QString updateDate;
QDate updateDateFormat;
int updateMonth;
int updateDay;
int updateYear;
int updateCustomerID;
double updateProductPrice;
int updateQuantity;
QString updateProductDescription;

Inventory::Inventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inventory)
{
    ui->setupUi(this);
}

Inventory::~Inventory()
{
    delete ui;
}



void Inventory::on_Add_clicked()
{
    database.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
    QSqlQuery qry;
    if (database.open())
    {
        qDebug() << qry.prepare("INSERT INTO items (Month, Day, Year, CustomerPurchasedID, PriceOfProduct, Quantity, ProductDescription)" "VALUES(:Month, :Day, :Year, :customerID, :ROUND(productPrice,2), :quantity, :productDescription)");
        qDebug() << qry.lastError().text();
        qry.bindValue(0, originalMonth);
        qry.bindValue(1, originalDay);
        qry.bindValue(2, originalYear);
        qry.bindValue(3, originalCustomerID);
        qry.bindValue(4, originalProductPrice);
        qry.bindValue(5, originalQuantity);
        qry.bindValue(6, originalProductDescription);

        if (qry.exec())
        {
            qDebug() << "\nDatabase worked";

        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nDatabase did not work";
        }
        database.close();
    }
}


void Inventory::on_originalDate_2_textChanged()
{
    originalDate = ui->originalDate_2->toPlainText();
    originalDateFormat = QDate::fromString(originalDate,"MM/dd/yyyy");
}


void Inventory::on_originalCustomerPurchased_textChanged()
{
    originalCustomerID = ui->originalCustomerPurchased->toPlainText().toInt();
}


void Inventory::on_originalPriceOfProduct_textChanged()
{
    originalProductPrice = ui->originalPriceOfProduct->toPlainText().toDouble();
}



void Inventory::on_originalQuantity_textChanged()
{
    originalQuantity = ui->originalQuantity->toPlainText().toInt();
}


void Inventory::on_originalProductDescription_textChanged()
{
    originalProductDescription = ui->originalProductDescription->toPlainText();
}


void Inventory::on_updatedDate_textChanged()
{
    updateDate = ui->updatedDate->toPlainText();
    updateDateFormat = QDate::fromString(updateDate,"MM/dd/yyyy");
}


void Inventory::on_updatedCustomerPurchased_textChanged()
{
    updateCustomerID = ui->updatedCustomerPurchased->toPlainText().toInt();
}


void Inventory::on_updatedPriceOfProduct_textChanged()
{
    updateProductPrice = ui->updatedPriceOfProduct->toPlainText().toDouble();
}


void Inventory::on_updatedQuantity_textChanged()
{
    updateQuantity = ui->updatedQuantity->toPlainText().toInt();
}


void Inventory::on_updatedProductDescription_textChanged()
{
    updateProductDescription = ui->updatedProductDescription->toPlainText();
}



void Inventory::on_Update_clicked()
{
    database.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
    QSqlQuery qry;
    if (database.open())
    {
        qry.prepare("DELETE FROM items WHERE ProductDescription = '"+originalProductDescription+"'");
        qDebug() << qry.lastError().text();
        if (qry.exec())
        {
            qDebug() << "update deleted fine";
                    qDebug() << qry.lastError().text();
        }
        else
        {
            qDebug() << "update deleted did not work";
                    qDebug() << qry.lastError().text();
        }
        qry.clear();
        qDebug() << qry.prepare("INSERT INTO items (Month, Day, Year, CustomerPurchasedID, PriceOfProduct, Quantity, ProductDescription)" "VALUES(:Month, :Day, :Year, :customerID, :ROUND(productPrice,2), :quantity, :productDescription)");
        qDebug() << qry.lastError().text();
        qry.bindValue(0, updateMonth);
        qry.bindValue(1, updateDay);
        qry.bindValue(2, updateYear);
        qry.bindValue(3, updateCustomerID);
        qry.bindValue(4, updateProductPrice);
        qry.bindValue(5, updateQuantity);
        qry.bindValue(6, updateProductDescription);
        if (qry.exec())
        {
            qDebug() << "update add fine";
                    qDebug() << qry.lastError().text();

        }
        else
        {
            qDebug() << "update add did not work";
                    qDebug() << qry.lastError().text();
        }
        database.close();
    }

}


void Inventory::on_Delete_clicked()
{
    database.setDatabaseName("C:/Users/Santiago/Documents/QT Stuff/FinalProjectCS1C/items.db");
    QSqlQuery qry;
    if (database.open())
    {
        qry.prepare("DELETE FROM items WHERE ProductDescription = '"+originalProductDescription+"'");
        qDebug() << qry.lastError().text();
        if (qry.exec())
        {
            qDebug() << "delete fine";
                    qDebug() << qry.lastError().text();

        }
        else
        {
            qDebug() << "delete did not work";
                    qDebug() << qry.lastError().text();
        }
        database.close();
    }
}
