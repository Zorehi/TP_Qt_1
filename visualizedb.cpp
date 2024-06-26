#include "visualizedb.h"
#include "mainwindow.h"
#include "ui_visualizedb.h"
#include "profilpage.h"

VisualizeDb::VisualizeDb(User& user, Profil& profil, Database& database, QWidget *parent)
    : QWidget(parent)
    ,ui(new Ui::VisualizeDb), database(database), profil(profil), user(user)
{
    ui->setupUi(this);
    setFixedSize(615,560);
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
    connect(ui->buttonBack, &QPushButton::clicked, this, &VisualizeDb::onClickRetour);
    connect(ui->buttonDelete, &QPushButton::clicked, this, &VisualizeDb::onClickDelete);
    connect(ui->buttonAdd, &QPushButton::clicked, this, &VisualizeDb::onClickAdd);
    connect(ui->SQLButton, &QPushButton::clicked,this, &VisualizeDb::onClickSQLButton);

    ui->buttonDelete->setEnabled(user.getDroits().hasDelete());
    ui->buttonAdd->setEnabled(user.getDroits().hasCreate());
    if (!user.getDroits().hasUpdate()) {
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

VisualizeDb::~VisualizeDb()
{
    QSqlDatabase db = QSqlDatabase::database();
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
    ProfilPage* profilPage = new ProfilPage(user, profil);
    ((MainWindow*)parent())->setCentralWidget(profilPage);
}

void VisualizeDb::onClickAdd() {
    QSqlTableModel *model = (QSqlTableModel*)ui->tableView->model();
    QSqlRecord record = model->record();
    if (model->insertRecord(-1, record)) {
        model->submitAll();
        model->select();
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Impossible d'insérer la ligne dans le modèle.");
    }
}

void VisualizeDb::onClickDelete() {
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if (!selection.empty()) {
        int row = selection.first().row();
        QSqlTableModel *model = (QSqlTableModel*)ui->tableView->model();
        model->removeRow(row);
        model->submitAll();
        model->select();
    }
}


void VisualizeDb::onClickSQLButton(){

    QString sqlQuery = ui->SQLText->toPlainText().trimmed();

    QSqlQuery query;

    QString queryType = sqlQuery.trimmed().split(" ").at(0).toUpper();
    if (queryType == "SELECT" && !user.getDroits().hasRead()) {
        qDebug() << "L'utilisateur n'a pas le droit de lire les données.";
        return;
    } else if (queryType == "INSERT" && !user.getDroits().hasCreate()) {
        qDebug() << "L'utilisateur n'a pas le droit d'insérer des données.";
        return;
    } else if (queryType == "UPDATE" && !user.getDroits().hasUpdate()) {
        qDebug() << "L'utilisateur n'a pas le droit de mettre à jour les données.";
        return;
    } else if (queryType == "DELETE" && !user.getDroits().hasDelete()) {
        qDebug() << "L'utilisateur n'a pas le droit de supprimer les données.";
        return;
    }

    // Exécuter la requête SQL
    if (query.exec(sqlQuery)) {
        if (queryType == "SELECT") {
            QSqlQueryModel *queryModel = new QSqlQueryModel();
            queryModel->setQuery(query);
            ui->tableView->setModel(queryModel);
        } else {
            qDebug() << "Requête exécutée avec succès.";
        }
    } else {
        qDebug() << "Erreur SQL:" << query.lastError().text();
    }
}
