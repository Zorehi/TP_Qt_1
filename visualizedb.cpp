#include "visualizedb.h"
#include "ui_visualizedb.h"

visualizedb::visualizedb(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::visualizedb)
{
    ui->setupUi(this);
}

visualizedb::~visualizedb()
{
    delete ui;
}
