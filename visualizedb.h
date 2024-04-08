#ifndef VISUALIZEDB_H
#define VISUALIZEDB_H

#include <QtSql>
#include <QListWidget>
#include "database.h"
#include "user.h"

namespace Ui {
class VisualizeDb;
}

class VisualizeDb : public QWidget
{
    Q_OBJECT

public:
    explicit VisualizeDb(User& user, Profil& profil, Database& database, QWidget *parent = nullptr);
    ~VisualizeDb();

private slots:
    void showTable(QListWidgetItem* item);
    void onClickRetour();
    void onClickAdd();
    void onClickDelete();
    void onClickSQLButton();

private:
    Ui::VisualizeDb *ui;
    Database& database;
    Profil& profil;
    User& user;
};

#endif // VISUALIZEDB_H
