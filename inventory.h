#ifndef INVENTORY_H
#define INVENTORY_H

#include <QDialog>

namespace Ui {
class Inventory;
}

class Inventory : public QDialog
{
    Q_OBJECT

public:
    explicit Inventory(QWidget *parent = nullptr);
    ~Inventory();

private slots:
    void on_Add_clicked();

    void on_originalDate_2_textChanged();

    void on_originalCustomerPurchased_textChanged();

    void on_originalPriceOfProduct_textChanged();

    void on_originalQuantity_textChanged();

    void on_originalProductDescription_textChanged();

    void on_updatedDate_textChanged();

    void on_updatedCustomerPurchased_textChanged();

    void on_updatedPriceOfProduct_textChanged();

    void on_updatedQuantity_textChanged();

    void on_updatedProductDescription_textChanged();

    void on_Update_clicked();

    void on_Delete_clicked();

private:
    Ui::Inventory *ui;
};

#endif // INVENTORY_H
