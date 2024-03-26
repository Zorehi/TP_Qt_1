#ifndef VISUALIZEDB_H
#define VISUALIZEDB_H

#include <QtSql>
#include <QListWidget>
#include "database.h"
#include "profil.h"

namespace Ui {
class VisualizeDb;
}

class VisualizeDb : public QWidget
{
    Q_OBJECT

public:
    explicit VisualizeDb(Profil& profil, Database& database, QWidget *parent = nullptr);
    ~VisualizeDb();

private slots:
    void showTable(QListWidgetItem* item);
    void onClickRetour();

private:
    Ui::VisualizeDb *ui;
    Database& database;
    Profil& profil;
};

#endif // VISUALIZEDB_H
