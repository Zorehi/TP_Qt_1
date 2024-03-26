#include "profilpage.h"
#include "ui_profilpage.h"
#include "listtable.h"
#include <QFileDialog>

ProfilPage::ProfilPage(Profil* profilpage, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilPage),
    profil(profilpage)
{
    if (!profil) {
        qDebug() << "Profil pointer is null!";
        // Traitez le cas où le pointeur est nul selon votre logique métier
    }

    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &ProfilPage::showListTable);
    connect(ui->addButton, &QPushButton::clicked, this, &ProfilPage::openFileDialog);
    updateListWidget(profil->getDbList());
}

void ProfilPage::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);

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
    if (!filePath.isEmpty()) {
        if (profil) {
            qDebug() << "Selected Name:" << profil->getName();
        }
        qDebug() << "Selected Name:" << fileName;
        Database newDatabase(filePath.toStdString());
        newDatabase.setName(fileName.toStdString());
        newDatabase.setPath(filePath.toStdString()); // Ajouter le chemin du fichier à la base de données
        qDebug() << "Selected Name:" << profil->getName();
        // Ajouter la base de données à la liste des bases de données dans le profil
        profil->getDbList().push_back(newDatabase);
        updateListWidget(profil->getDbList());
    }
}

void ProfilPage::updateListWidget(const std::vector<Database>& dbList) {
    // Nettoyer le contenu actuel du listWidget
    ui->listWidget->clear();
    // Parcourir la liste des databases et ajouter les noms au listWidget
    for (const Database& db : dbList) {
        ui->listWidget->addItem(QString::fromStdString(db.getName()));
    }
}
