#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QFile>
#include <QSqlError>

void setupDatabasePurchases(QString filePath);
void setupDatabasePeople(QString filePath);
void clearDatabase();
void addTotaltoDatabase();
void addRebatetoDatabase();









//was trying to consolidate the database so we wouldn't have to set database name everytime... it didnt work
//class Data
//{
//public:
//    Data(QSqlDatabase *database);
//    QSqlDatabase database;
//    void connClose()
//    {
//        database.close();
//        database.removeDatabase(QSqlDatabase::defaultConnection);
//    }
//    bool connOpen()
//    {
//        database=QSqlDatabase::addDatabase("QSQLITE");
//        database.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");

//        if(!database.open())
//        {
//            qDebug()<<("Failed to open database");
//            return false;
//        }
//        else
//        {
//            qDebug()<<("Connected....");
//            return true;
//        }
//    }


//};


#endif // DATABASE_H
