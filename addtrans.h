#ifndef ADDTRANS_H
#define ADDTRANS_H

#include <QDialog>

namespace Ui {
class AddTrans;
}

class AddTrans : public QDialog
{
    Q_OBJECT

public:
    explicit AddTrans(QWidget *parent = nullptr);
    ~AddTrans();

private slots:
    void on_Date_textChanged();

    void on_CustomerPurchased_textChanged();

    void on_PriceOfProduct_textChanged();

    void on_Quantity_textChanged();

    void on_ProductDescription_textChanged();

    void on_addItem_clicked();

private:
    Ui::AddTrans *ui;
};

#endif // ADDTRANS_H
