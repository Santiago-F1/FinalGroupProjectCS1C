#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QFile>

void setupDatabasePurchases(QString filePath);
void setupDatabasePeople(QString filePath);

#endif // DATABASE_H
