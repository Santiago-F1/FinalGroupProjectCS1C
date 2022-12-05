#ifndef REBATE_H
#define REBATE_H
//#include"database.h"
#include<QTableView>
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

private slots:
    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Rebate *ui;

};



#endif // REBATE_H
