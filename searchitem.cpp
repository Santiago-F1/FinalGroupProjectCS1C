#include "searchitem.h"
#include "ui_searchitem.h"

SearchItem::SearchItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchItem)
{
    ui->setupUi(this);
}

SearchItem::~SearchItem()
{
    delete ui;
}
