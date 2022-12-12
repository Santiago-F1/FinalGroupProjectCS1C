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

private slots:
    void on_inputDate_textChanged();

    void on_pushButton_clicked();

private:
    Ui::MemStatus *ui;
};

#endif // MEMSTATUS_H
