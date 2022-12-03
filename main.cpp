#include "admin.h"
#include "storemanager.h"
#include "loginui.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginui l;
    Storemanager s;
    Admin a1;
    setupDatabasePurchases(":inputFiles/day1.txt");
    setupDatabasePurchases(":inputFiles/day2.txt");
    setupDatabasePurchases(":inputFiles/day3.txt");
    setupDatabasePurchases(":inputFiles/day4.txt");
    setupDatabasePurchases(":inputFiles/day5.txt");
    setupDatabasePurchases(":inputFiles/day6.txt");
    setupDatabasePurchases(":inputFiles/day7.txt");
    setupDatabasePeople(":inputFiles/warehouse shoppers-1.txt");


   // MainWindow w; //this will not be shown yet until login
    l.show();
    return a.exec();
}
