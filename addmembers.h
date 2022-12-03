#ifndef ADDMEMBERS_H
#define ADDMEMBERS_H

#include <QDialog>

namespace Ui {
class AddMembers;
}

class AddMembers : public QDialog
{
    Q_OBJECT

public:
    explicit AddMembers(QWidget *parent = nullptr);
    ~AddMembers();

private:
    Ui::AddMembers *ui;
};

#endif // ADDMEMBERS_H
