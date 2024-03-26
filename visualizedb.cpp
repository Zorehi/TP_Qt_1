#include "visualizedb.h"
#include "mainwindow.h"
#include "ui_visualizedb.h"

VisualizeDb::VisualizeDb(Profil& profil, Database& database, QWidget *parent)
    : QWidget(parent)
    ,ui(new Ui::VisualizeDb), database(database), profil(profil)
{
    ui->setupUi(this);

    QSqlDatabase db;
    // Connexion à la base de données SQLite
    if (QSqlDatabase::contains(database.getPath().c_str())) {
        QSqlDatabase db = QSqlDatabase::database(database.getPath().c_str());
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(database.getPath().c_str());
    }

    // Vérification si la base de données est ouverte
    if (!db.open()) {
        qDebug() << "Impossible d'ouvrir la base de données.";
    } else {
        // Récupération des noms des tables
        QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table';");
        while (query.next()) {
            ui->listWidget->addItem(query.value(0).toString());
        }
    }
    connect(ui->listWidget, &QListWidget::itemClicked, this, &VisualizeDb::showTable);
    connect(ui->pushButton, &QPushButton::clicked, this, &VisualizeDb::onClickRetour);
}

VisualizeDb::~VisualizeDb()
{
    QSqlDatabase db = QSqlDatabase::database(database.getPath().c_str());
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

void VisualizeDb::showTable(QListWidgetItem* item) {
    // Récupérer le nom de la table sélectionnée
    QString tableName = item->text();

    QSqlDatabase db = QSqlDatabase::database();

    // Vérification si la base de données est ouverte
    if (!db.open()) {
        qDebug() << "Impossible d'ouvrir la base de données.";
    } else {
        // Création du modèle de table
        QSqlTableModel *model = new QSqlTableModel(ui->tableView, db);
        model->setEditStrategy(QSqlTableModel::OnFieldChange);
        model->setTable(tableName);
        model->select();

        // Mettre à jour le modèle de données de QTableView
        ui->tableView->setModel(model);
        ui->tableView->show();
    }
}

void VisualizeDb::onClickRetour() {
    ProfilPage* profilPage = new ProfilPage(profil);
    ((MainWindow*)parent())->setCentralWidget(profilPage);
}
