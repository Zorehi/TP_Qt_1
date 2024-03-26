#include "profilpage.h"
#include "ui_profilpage.h"
#include "listtable.h"
#include <QFileDialog>

ProfilPage::ProfilPage(const QString& profileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilPage)
{

    ui->setupUi(this);
    // Afficher le nom du profil dans un QTextBrowser sur la page
    ui->listWidget->addItem(profileName);

    // Connecter le signal clicked() du bouton à la fonction pour afficher ListTable
    connect(ui->pushButton, &QPushButton::clicked, this, &ProfilPage::showListTable);
    connect(ui->addButton, &QPushButton::clicked, this, &ProfilPage::openFileDialog);
}

void ProfilPage::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);

    // Redimensionner la page ProfilPage à une largeur de 600 pixels et une hauteur de 400 pixels
    resize(1000, 1000);
}
ProfilPage::~ProfilPage()
{
    delete ui;
}

void ProfilPage::showListTable() {
    if(ui->listWidget->currentItem() == nullptr) {
        // Aucun élément sélectionné, ne rien faire
        return;
    }
    // Créer une instance de ListTable
    ListTable *listTable = new ListTable(this);

    // Afficher ListTable
    listTable->show();
}

void ProfilPage::openFileDialog() {

    // Ouvrir un QFileDialog pour sélectionner un fichier
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner un fichier", "", "Fichiers (*.txt *.db)");
    QString fileName = QFileInfo(filePath).fileName();
    // Vérifier si un fichier a été sélectionné
    if (!filePath.isEmpty()) {
        ui->listWidget->addItem(fileName);
    }
}
