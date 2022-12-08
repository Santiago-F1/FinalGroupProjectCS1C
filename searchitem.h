#ifndef SEARCHITEM_H
#define SEARCHITEM_H
#include "qsqlerror.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QDialog>

namespace Ui {
class SearchItem;
}

class SearchItem : public QDialog
{
    Q_OBJECT

public:
    explicit SearchItem(QWidget *parent = nullptr);
    ~SearchItem();

private slots:
    void on_addmembers_2_clicked();

private:
    Ui::SearchItem *ui;
};

#endif // SEARCHITEM_H
