#include "updatemembers.h"
#include "ui_updatemembers.h"

UpdateMembers::UpdateMembers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateMembers)
{
    ui->setupUi(this);
    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");
    QSqlQuery qry;
    QSqlQuery qry2;
    QSqlQueryModel *modal=new QSqlQueryModel;
    QSqlQueryModel *modal2=new QSqlQueryModel;

    database1.open();


        qry.prepare("SELECT MemberName, MembershipType, MemberNumber, shouldUpgrade AS Status FROM Members WHERE shouldUpgrade = 'UPGRADE'");
        if (qry.exec())
        {
            modal->setQuery(std::move(qry));

            ui->regular->setModel(modal);
           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

            ui->regular->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
            ui->regular->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
            ui->regular->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
            ui->regular->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

            qDebug() << "\n GOOD DISPLAYING THING";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nfailed to update add/delete amount";
        }

        qry2.prepare("SELECT MemberName, MembershipType, MemberNumber, shouldUpgrade AS Status FROM Members WHERE shouldUpgrade = 'DOWNGRADE'");
        if (qry2.exec())
        {
            modal2->setQuery(std::move(qry2));

            ui->exec->setModel(modal2);
           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

            ui->exec->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
            ui->exec->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
            ui->exec->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
            ui->exec->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

            qDebug() << "\n GOOD DISPLAYING exec in update members";
        }
        else
        {
            qDebug() << qry2.executedQuery();
            qDebug() << qry2.lastError().text();
            qDebug() << "\nfailed to display exec in update members ";
        }

   // delete modal;
    database1.close();

}


UpdateMembers::~UpdateMembers()
{
    delete ui;
}
