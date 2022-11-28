#ifndef STOREMANAGER_H
#define STOREMANAGER_H

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

private:
    Ui::Storemanager *ui;

};

#endif // STOREMANAGER_H
