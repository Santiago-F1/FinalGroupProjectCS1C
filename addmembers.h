#ifndef ADDMEMBERS_H
#define ADDMEMBERS_H
#include<QDate>
#include <QDialog>
#include "qsqlerror.h"
#include<QSqlQueryModel>
#include<QSqlQuery>

namespace Ui {
class AddMembers;
}

class AddMembers : public QDialog
{
    Q_OBJECT

public:
    explicit AddMembers(QWidget *parent = nullptr);
    ~AddMembers();

private slots:




    void on_addmembers_2_clicked();

    void on_deletemembers_2_clicked();

private:
    Ui::AddMembers *ui;
//    QSqlQuery *qry;
//    QSqlQueryModel *modal;
};

#endif // ADDMEMBERS_H
