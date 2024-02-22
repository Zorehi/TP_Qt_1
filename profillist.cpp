#include "profillist.h"
#include "mainwindow.h"
#include "ui_profillist.h"

ProfilList::ProfilList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProfilList)
{
    ui->setupUi(this);

    // Connecter le signal clicked du bouton "Déconnexion" à la fonction onDeconnexionClicked
    connect(ui->pushButton_2, &QPushButton::clicked, this, &ProfilList::onDeconnexionClicked);
}


void ProfilList::onDeconnexionClicked() {
    // Changer la page centrale vers LoginPage
    ((MainWindow*)parent())->setCentralWidget(new MainWindow());

    // Supprimer ProfilList
    deleteLater();
}

void ProfilList::updateTextBrowser(const std::vector<Profil>& profilList) {
    // Nettoyer le contenu actuel du QTextBrowser
    ui->textBrowser->clear();

    // Parcourir la liste des profils et ajouter les noms au QTextBrowser
    for (const Profil& profil : profilList) {
        ui->textBrowser->append(profil.getName().c_str());
    }
}

void ProfilList::updateComboBox(const std::vector<Profil>& profilList){
    for (const Profil& profil : profilList) {
        ui->comboBox->addItem(profil.getName().c_str());
    }
}
