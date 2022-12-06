#ifndef STOREMANAGER_H
#define STOREMANAGER_H
#include"salesreport.h"
#include"storeproducts.h"
#include"searchitem.h"
#include"addtrans.h"

#include"mempurchases.h"
#include"rebate.h"
#include"memstatus.h"
#include <QMainWindow>
#include<QDateTime>

namespace Ui {
class Storemanager;
}

class Storemanager : public QMainWindow
{
    Q_OBJECT

public:
    explicit Storemanager(QWidget *parent = nullptr);
    ~Storemanager();

private slots:
    void on_SalesReport_clicked();

    void on_StoreProducts_clicked();

    void on_SearchItem_clicked();

    void on_AddTrans_clicked();



    void on_MemPurchases_clicked();

    void on_Rebate_clicked();

    void on_MemStatus_clicked();

private:
    Ui::Storemanager *ui;
    SalesReport *Sales;
    StoreProducts *Store;
    SearchItem *Search;
    AddTrans *addTrans;

    MemPurchases *memP;
    Rebate *rebate;
    MemStatus *memStatus;

};

#endif // STOREMANAGER_H
