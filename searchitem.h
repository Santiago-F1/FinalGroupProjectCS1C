#ifndef SEARCHITEM_H
#define SEARCHITEM_H

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

private:
    Ui::SearchItem *ui;
};

#endif // SEARCHITEM_H
