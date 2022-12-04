#include "admin.h"
#include "storemanager.h"
#include "loginui.h"
#include <QApplication>
#include "database.h"
#include <QStandardPaths>
#include <QFile>
#include <QDebug>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginui l;
    Storemanager s;
    Admin a1;

    QString downloadFolder = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    downloadFolder.append("/readDatabase.txt");

    QFile file(downloadFolder);

    QTextStream stream(&file);

    //clearDatabase();
    if (file.open(QIODevice::ReadWrite))
    {
        QString isDatabaseInputed = stream.readLine();
        qInfo() << isDatabaseInputed;
        if (isDatabaseInputed == "")
        {
            stream << "true";
            qInfo() << "Writing to File";
            setupDatabasePurchases(":inputFiles/day1.txt");
            setupDatabasePurchases(":inputFiles/day2.txt");
            setupDatabasePurchases(":inputFiles/day3.txt");
            setupDatabasePurchases(":inputFiles/day4.txt");
            setupDatabasePurchases(":inputFiles/day5.txt");
            setupDatabasePurchases(":inputFiles/day6.txt");
            setupDatabasePurchases(":inputFiles/day7.txt");
            setupDatabasePeople(":inputFiles/warehouse shoppers-1.txt");
        }
        else
        {
            qInfo() << "File already written";
        }
    }


    file.close();


   // MainWindow w; //this will not be shown yet until login
    l.show();
    return a.exec();
}
