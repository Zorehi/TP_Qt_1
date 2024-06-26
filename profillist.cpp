#include "profillist.h"
#include "profilpage.h"
#include "mainwindow.h"
#include "ui_profillist.h"

ProfilList::ProfilList(User& user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilList),
    user(user)
{
    ui->setupUi(this);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &ProfilList::onDeconnexionClicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &ProfilList::onChangeClicked);

    for (const Profil& profil : user.getProfilList()) {
        ui->comboBox->addItem(profil.getName().c_str());
    }

    for (const Profil& profil : user.getProfilList()) {
        ui->textBrowser->append(profil.getName().c_str());
    }
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

void ProfilList::onChangeClicked() {
    QString selectedName = ui->comboBox->currentText();

    Profil* profilFound = nullptr;  // Initialisation à nullptr

    // Chercher le profil correspondant au nom sélectionné
    for (Profil& profil : user.getProfilList()) {
        if (profil.getName().c_str() == selectedName) {
            profilFound = &profil;  // Affecter l'adresse du profil trouvé
            break;  // Sortir de la boucle une fois que le profil est trouvé
        }
    }
    if (profilFound) {
        // Créer une instance de ProfilePage en lui transmettant le profil choisi
        ProfilPage *profilePage = new ProfilPage(user, *profilFound, this);

        // Définir ProfilePage comme widget central de la fenêtre principale
        ((MainWindow*)parent())->setCentralWidget(profilePage);
    } else {
        qDebug() << "Profil non trouvé.";
    }
}


