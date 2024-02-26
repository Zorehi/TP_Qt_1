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
    connect(ui->pushButton, &QPushButton::clicked, this, &ProfilList::onChangeClicked);
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

void ProfilList::onChangeClicked() {
    // Récupérer le nom sélectionné dans le QComboBox
    QString selectedName = ui->comboBox->currentText();

    // Créer une instance de ProfilePage en lui transmettant le nom choisi
    ProfilPage *profilePage = new ProfilPage(selectedName);

    // Définir ProfilePage comme widget central de la fenêtre principale
    ((MainWindow*)parent())->setCentralWidget(profilePage);
}


