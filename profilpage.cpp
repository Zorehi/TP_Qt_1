#include "profilpage.h"
#include "mainwindow.h"
#include "ui_profilpage.h"
#include "visualizedb.h"
#include <QFileDialog>

ProfilPage::ProfilPage(Profil& profil, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilPage),
    profil(profil)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &ProfilPage::showListTable);
    connect(ui->addButton, &QPushButton::clicked, this, &ProfilPage::openFileDialog);
    updateListWidget(profil.getDbList());
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

    QString selectedName = ui->listWidget->currentItem()->text();

    Database* dbselected = nullptr;
    for (Database& db : profil.getDbList()) {
        if (db.getName().c_str() == selectedName) {
            dbselected = &db;
            break;
        }
    }

    VisualizeDb* visualizedb = new VisualizeDb(profil, *dbselected, this);

    ((MainWindow*)parent())->setCentralWidget(visualizedb);
}

void ProfilPage::openFileDialog() {

    // Ouvrir un QFileDialog pour sélectionner un fichier
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner un fichier", "", "Fichiers (*.txt *.db)");
    QString fileName = QFileInfo(filePath).fileName();
    if (!filePath.isEmpty()) {
        qDebug() << "Selected Name:" << fileName;
        Database newDatabase;
        newDatabase.setName(fileName.toStdString());
        newDatabase.setPath(filePath.toStdString()); // Ajouter le chemin du fichier à la base de données
        qDebug() << "Selected Name:" << profil.getName();
        // Ajouter la base de données à la liste des bases de données dans le profil
        profil.getDbList().push_back(newDatabase);
        updateListWidget(profil.getDbList());
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
