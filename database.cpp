#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QFile>
#include "database.h"
#include "qsqlquerymodel.h"
#include <QDate>
#include <QCoreApplication>
#include <QSqlError>
#include <QStandardPaths>


QSqlDatabase database =QSqlDatabase::addDatabase("QSQLITE");


void setupDatabasePurchases(QString filePath)
{
    database.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");
    QSqlQuery qry;

    if (database.open())
    {
        int Month;
        int Day;
        int Year;
        int CustomerPurchasedID;
        QString ProductDescription;
        double PriceOfProduct;
        int Quantity;
        QFile file(filePath);
        if(!file.exists())
        {
            qCritical() << "File does not exist";
        }
        if (!file.open(QIODevice::ReadOnly))
        {
            qCritical() << file.errorString();
        }
        QTextStream stream(&file);
        while(!stream.atEnd())
        {

            QString dd =stream.readLine();
            QDate da=QDate::fromString(dd,"M/d/yyyy");
            Month = da.month();
            Day = da.day();
            Year = da.year();
            qInfo() << "Month: " << Month << " Day: " << Day << " Year: " << Year;
            QString line;
            line=stream.readLine();
            CustomerPurchasedID = line.toInt();
            line = stream.readLine();
            ProductDescription = line;
            line = stream.readLine();
            PriceOfProduct = line.toDouble();
            line = stream.readLine();
            Quantity = line.toInt();


            qDebug() << qry.prepare("INSERT or IGNORE INTO items (Month, Day, Year, CustomerPurchasedID, PriceOfProduct, Quantity, ProductDescription)" "VALUES(:Month, :Day, :Year, :CustomerPurchasedID, :ROUND(PriceOfProduct,2), :Quantity, :ProductDescription)");
            qDebug() << qry.lastError().text();
            qry.bindValue(0, Month);
            qry.bindValue(1, Day);
            qry.bindValue(2, Year);
            qry.bindValue(3, CustomerPurchasedID);
            qry.bindValue(4, PriceOfProduct);
            qry.bindValue(5, Quantity);
            qry.bindValue(6, ProductDescription);
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
        }
    database.close();
    }
}

void setupDatabasePeople(QString filePath)
{
   //database.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");
    QSqlQuery qry;
    if (database.open())
    {
        QString memberName;
        int memberID;
        QString membershipType;
        QDate expirationDate;
        double TotalAmountSpent = 0.0;
        double RebateAmount = 0.0;
        int Month;
        int Day;
        int Year;


        QFile file(filePath);
        if(!file.exists())
        {
            qCritical() << "File does not exist";
        }
        if (!file.open(QIODevice::ReadOnly))
        {
            qCritical() << file.errorString();
        }
        QTextStream stream(&file);
        while(!stream.atEnd())
        {

            QString line;
            memberName=stream.readLine();
            memberID = stream.readLine().toInt();
            membershipType = stream.readLine();
            expirationDate = QDate::fromString(stream.readLine(),"MM/dd/yyyy");
            Month = expirationDate.month();
            Day = expirationDate.day();
            Year = expirationDate.year();

            qInfo() << "Month: " << Month << " Day: " << Day << " Year: " << Year;

            qDebug() << qry.prepare("INSERT or IGNORE INTO Members (MemberName, MemberNumber, MembershipType, TotalAmountSpent, RebateAmount, expirationMonth, expirationDay, expirationYear)" "VALUES(?,?,?,?,?,?,?,?)");
            qDebug() << qry.lastError().text();
            qry.bindValue(0, memberName);
            qry.bindValue(1, memberID);
            qry.bindValue(2, membershipType);
            qry.bindValue(3, TotalAmountSpent);
            qry.bindValue(4, RebateAmount);
            qry.bindValue(5, Month);
            qry.bindValue(6, Day);
            qry.bindValue(7, Year);
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
        }
    database.close();
    }
}

void addTotaltoDatabase()           //not including tax
{
    //database.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");

    QSqlQuery qry;

    if(database.open())
    {

        qry.prepare("UPDATE Members SET TotalAmountSpent = (SELECT ROUND(SUM(PriceOfProduct)*SUM(Quantity),2) FROM items WHERE CustomerPurchasedID = MemberNumber)");
        if (qry.exec())
        {
            qDebug() << "\nSuccsessfully updated total amount";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nFailed to update member amount total";
        }
    }
    database.close();
}

void addRebatetoDatabase()
{
    //database.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");


    QSqlQuery qry;

    if(database.open())
    {

        qry.prepare("UPDATE Members SET RebateAmount =ROUND(TotalAmountSpent*.02,2)");
        if (qry.exec())
        {
            qDebug() << "\nUpdating Rebate Amount successful";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nfailed to update rebate amount";
        }
    }
    qry.prepare("UPDATE Members SET RebateAmount=0, TotalAmountSpent =0 WHERE RebateAmount IS NULL OR TotalAmountSpent IS NULL");
    if (qry.exec())
    {
        qDebug() << "\nUpdated Nulls properlly";
    }
    else
    {
        qDebug() << qry.executedQuery();
        qDebug() << qry.lastError().text();
        qDebug() << "\nI AM AN UTTER FAILURE in database";
    }
    database.close();
}

void shouldupgrade()
{
    QSqlQuery qry;

    if(database.open())
    {

        qry.prepare("UPDATE Members SET shouldUpgrade = 'DOWNGRADE' WHERE RebateAmount < '125' AND MembershipType = 'Executive'");
        if (qry.exec())
        {
            qDebug() << "\nUpdated the downgrade status";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nfailed to update in should upgrade";
        }
    }
    qry.prepare("UPDATE Members SET shouldUpgrade = 'UPGRADE' WHERE RebateAmount > '125' AND MembershipType = 'Regular'");
    if (qry.exec())
    {
        qDebug() << "\nUpdated update status";
    }
    else
    {
        qDebug() << qry.executedQuery();
        qDebug() << qry.lastError().text();
        qDebug() << "\nI AM AN UTTER FAILURE in should upgrade";
    }
    database.close();
}



void clearDatabase()
{
   database.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");
    QSqlQuery qry;
    if (database.open())
    {
        qry.exec(QString("DELETE FROM items"));
        qInfo() << qry.lastError();
        qry.exec(QString("DELETE FROM Members"));
        qInfo() << qry.lastError();

    }
    database.close();

}




