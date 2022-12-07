#ifndef UPDATEMEMBERS_H
#define UPDATEMEMBERS_H
#include "qsqlerror.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QDialog>

namespace Ui {
class UpdateMembers;
}

class UpdateMembers : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateMembers(QWidget *parent = nullptr);
    ~UpdateMembers();

private:
    Ui::UpdateMembers *ui;
};

#endif // UPDATEMEMBERS_H
