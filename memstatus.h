#ifndef MEMSTATUS_H
#define MEMSTATUS_H

#include <QDialog>

namespace Ui {
class MemStatus;
}

class MemStatus : public QDialog
{
    Q_OBJECT

public:
    explicit MemStatus(QWidget *parent = nullptr);
    ~MemStatus();

private:
    Ui::MemStatus *ui;
};

#endif // MEMSTATUS_H
