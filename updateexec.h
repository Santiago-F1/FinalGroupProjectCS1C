#ifndef UPDATEEXEC_H
#define UPDATEEXEC_H

#include <QDialog>

namespace Ui {
class UpdateExec;
}

class UpdateExec : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateExec(QWidget *parent = nullptr);
    ~UpdateExec();

private:
    Ui::UpdateExec *ui;
};

#endif // UPDATEEXEC_H
