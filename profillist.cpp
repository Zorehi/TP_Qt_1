#include "profillist.h"
#include "mainwindow.h"
#include "ui_profillist.h"

ProfilList::ProfilList(const std::vector<Profil>& profilList,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilList),
    profilList(profilList)

{
    ui->setupUi(this);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &ProfilList::onDeconnexionClicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &ProfilList::onChangeClicked);

}


void ProfilList::onDeconnexionClicked() {
    // Changer la page centrale vers LoginPage
    ((MainWindow*)parent())->setCentralWidget(new MainWindow());

    // Supprimer ProfilList
    deleteLater();
}
ProfilList::~ProfilList()
{
    delete ui;
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
    QString selectedName = ui->comboBox->currentText();

    Profil* profilFound = nullptr;  // Initialisation à nullptr

    // Chercher le profil correspondant au nom sélectionné
    for (const Profil& profil : this->profilList) {
        if (profil.getName().c_str() == selectedName) {
            profilFound = new Profil(profil);  // Affecter l'adresse du profil trouvé
            break;  // Sortir de la boucle une fois que le profil est trouvé
        }
    }
    if (profilFound) {
        // Créer une instance de ProfilePage en lui transmettant le profil choisi
        ProfilPage *profilePage = new ProfilPage(profilFound, this);

        // Définir ProfilePage comme widget central de la fenêtre principale
        ((MainWindow*)parent())->setCentralWidget(profilePage);
    } else {
        qDebug() << "Profil non trouvé.";
    }
}


