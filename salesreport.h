#ifndef SALESREPORT_H
#define SALESREPORT_H

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

private:
    Ui::SalesReport *ui;
};

#endif // SALESREPORT_H
