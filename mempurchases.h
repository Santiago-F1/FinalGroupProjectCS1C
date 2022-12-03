#ifndef MEMPURCHASES_H
#define MEMPURCHASES_H

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

private:
    Ui::MemPurchases *ui;
};

#endif // MEMPURCHASES_H
