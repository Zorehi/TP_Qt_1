#include "visualizedb.h"
#include "mainwindow.h"
#include "ui_visualizedb.h"

visualizedb::visualizedb(Profil& profil, Database& database, QWidget *parent)
    : QWidget(parent)
    ,ui(new Ui::visualizedb), database(database), profil(profil), db(QSqlDatabase())
{
    ui->setupUi(this);

    // Connexion à la base de données SQLite
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(database.getPath().c_str()); // Remplacez par le chemin vers votre base de données

    // Vérification si la base de données est ouverte
    if (!db.open()) {
        qDebug() << "Impossible d'ouvrir la base de données.";
    } else {
        // Récupération des noms des tables
        QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table';");
        while (query.next()) {
            ui->listWidget->addItem(query.value(0).toString());
        }
        db.close();
    }
    connect(ui->listWidget, &QListWidget::itemClicked, this, &visualizedb::showTable);
    connect(ui->pushButton, &QPushButton::clicked, this, &visualizedb::onClickRetour);
}

visualizedb::~visualizedb()
{
    delete ui;
}

void visualizedb::showTable(QListWidgetItem* item) {
    // Récupérer le nom de la table sélectionnée
    QString tableName = item->text();

    // Création du modèle de table
    QSqlTableModel model(this, db);
    model.setTable(tableName);
    model.select();

    // Mettre à jour le modèle de données de QTableView
    ui->tableView->setModel(&model);
}

void visualizedb::onClickRetour() {
    ProfilPage* profilPage = new ProfilPage(profil);
    ((MainWindow*)parent())->setCentralWidget(profilPage);
}
