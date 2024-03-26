#ifndef VISUALIZEDB_H
#define VISUALIZEDB_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QListWidget>
#include "database.h"
#include "profil.h"

namespace Ui {
class visualizedb;
}

class visualizedb : public QWidget
{
    Q_OBJECT

public:
    explicit visualizedb(Profil& profil, Database& database, QWidget *parent = nullptr);
    ~visualizedb();

    void showTable(QListWidgetItem* item);
    void onClickRetour();

private:
    Ui::visualizedb *ui;
    QSqlDatabase db;
    Database& database;
    Profil& profil;
};

#endif // VISUALIZEDB_H
