#ifndef REBATE_H
#define REBATE_H

#include <QDialog>

namespace Ui {
class Rebate;
}

class Rebate : public QDialog
{
    Q_OBJECT

public:
    explicit Rebate(QWidget *parent = nullptr);
    ~Rebate();

private:
    Ui::Rebate *ui;
};

#endif // REBATE_H
