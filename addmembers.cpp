#include "addmembers.h"
#include "ui_addmembers.h"


AddMembers::AddMembers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMembers)
{
    ui->setupUi(this);
    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel;

    if(database1.open())
    {

        qry.prepare("SELECT MemberName, MemberNumber, MembershipType FROM Members");
        if (qry.exec())
        {
            modal->setQuery(std::move(qry));

            ui->tableView->setModel(modal);
           // ui->tableView->setStyleSheet("QHeaderView::section { background-color:red }");

            ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
            ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
            ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);


            qDebug() << "\nUpdating Member add/delete successful";
        }
        else
        {
            qDebug() << qry.executedQuery();
            qDebug() << qry.lastError().text();
            qDebug() << "\nfailed to update add/delete amount";
        }
    }
   // delete modal;
    database1.close();
}

AddMembers::~AddMembers()
{
    delete ui;
}


void AddMembers::on_addmembers_2_clicked()
{
    QSqlDatabase database1 =QSqlDatabase::addDatabase("QSQLITE");
    database1.setDatabaseName("C:/Users/duffy/OneDrive/Documents/finalcs1c/KasimAlexHSantiagoFinalProject/items.db");
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel;
    QString name, type;
    QDate date = QDate::currentDate();
    int month,day,year;
    month = date.month();
    day = date.day();
    year = date.year()+1;
    double rebate = 0.0;
    double total = 0.0;
    int num;
    //num= num.toInt();
    name = ui->nameEdit->text();
    num = ui->numberEdit->text().toInt();
    type = ui->memberEdit->text();

        if(database1.open())
        {

            qry.prepare("INSERT INTO Members (MemberName, MemberNumber, MembershipType, TotalAmountSpent, RebateAmount, expirationMonth, expirationDay, expirationYear) VALUES(:name, :num, :type, :total, :rebate, :month, :day, :year)");
            qry.bindValue(0,name);
            qry.bindValue(1,num);
            qry.bindValue(2,type);
            qry.bindValue(3,total);
            qry.bindValue(4,rebate);
            qry.bindValue(5,month);
            qry.bindValue(6,day);
            qry.bindValue(7,year);
            if (qry.exec())
            {
                qry.prepare("SELECT MemberName, MemberNumber, MembershipType FROM Members");
                qry.exec();

                modal->setQuery(std::move(qry));

                ui->tableView->setModel(modal);
                QString message = "Successfully added new Member";
               // ui->addError->setStyleSheet("QTextBrowser::addError { color:green }");
                ui->addError->setPlaceholderText(message);
                qDebug() << "\nAdding member successful";
            }
            else
            {
                QString message = "Failed to add new Member(Database issue)";

                ui->addError->setPlaceholderText(message);
                qDebug() << qry.executedQuery();
                qDebug() << qry.lastError().text();
                qDebug() << "\nfailed to add member";
            }
        }
    //    qry.prepare("UPDATE Members SET RebateAmount=0, TotalAmountSpent =0 WHERE RebateAmount IS NULL OR TotalAmountSpent IS NULL");
    //    if (qry.exec())
    //    {
    //        qDebug() << "\nUpdated Nulls properlly";
    //    }
    //    else
    //    {
    //        qDebug() << qry.executedQuery();
    //        qDebug() << qry.lastError().text();
    //        qDebug() << "\nI AM AN UTTER FAILURE in addmembers";
    //    }
        //delete modal;
        database1.close();
}





void AddMembers::on_deletemembers_2_clicked()
{

}




