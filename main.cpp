#include "admin.h"
#include "storemanager.h"
#include "loginui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginui l;
    Storemanager s;
    Admin a1;


   // MainWindow w; //this will not be shown yet until login
    l.show();
    return a.exec();
}
