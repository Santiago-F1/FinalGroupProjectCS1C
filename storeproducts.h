#ifndef STOREPRODUCTS_H
#define STOREPRODUCTS_H

#include <QDialog>

namespace Ui {
class StoreProducts;
}

class StoreProducts : public QDialog
{
    Q_OBJECT

public:
    explicit StoreProducts(QWidget *parent = nullptr);
    ~StoreProducts();

private:
    Ui::StoreProducts *ui;
};

#endif // STOREPRODUCTS_H
