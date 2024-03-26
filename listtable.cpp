#include "listtable.h"
#include "ui_listtable.h"

ListTable::ListTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListTable)
{
    ui->setupUi(this);
}

ListTable::~ListTable()
{
    delete ui;
}
