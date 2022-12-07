#ifndef MEMPURCHASES_H
#define MEMPURCHASES_H
#include "qsqlerror.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QDialog>

namespace Ui {
class MemPurchases;
}

class MemPurchases : public QDialog
{
    Q_OBJECT

public:
    explicit MemPurchases(QWidget *parent = nullptr);
    ~MemPurchases();

private slots:



    void on_pushButton_clicked();

private:
    Ui::MemPurchases *ui;
};

#endif // MEMPURCHASES_H
