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

private:
    Ui::AddTrans *ui;
};

#endif // ADDTRANS_H
