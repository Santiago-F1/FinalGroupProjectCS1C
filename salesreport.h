#ifndef SALESREPORT_H
#define SALESREPORT_H
#include "qsqlerror.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QDialog>

namespace Ui {
class SalesReport;
}

class SalesReport : public QDialog
{
    Q_OBJECT

public:
    explicit SalesReport(QWidget *parent = nullptr);
    ~SalesReport();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SalesReport *ui;
};

#endif // SALESREPORT_H
