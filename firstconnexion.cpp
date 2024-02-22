#include "firstconnexion.h"
#include "ui_firstconnexion.h"

FirstConnexion::FirstConnexion(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FirstConnexion)
{
    ui->setupUi(this);
}

FirstConnexion::~FirstConnexion()
{
    delete ui;
}
