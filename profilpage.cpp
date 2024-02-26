#include "profilpage.h"
#include "ui_profilpage.h"

ProfilPage::ProfilPage(const QString& profileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilPage)
{
    ui->setupUi(this);

    // Afficher le nom du profil dans un QTextBrowser sur la page
    ui->textBrowser->setText(profileName);
}

ProfilPage::~ProfilPage()
{
    delete ui;
}
