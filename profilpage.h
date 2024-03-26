#ifndef PROFILPAGE_H
#define PROFILPAGE_H

#include "profil.h"

#include "database.h"
#include <QWidget>
#include <QString>

namespace Ui {
class ProfilPage;
}

class ProfilPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilPage(Profil* profileName, QWidget *parent = nullptr);
    ~ProfilPage();

private slots:
    void showListTable();
    void openFileDialog();
protected:
    void paintEvent(QPaintEvent *event) override;
    void updateListWidget(const std::vector<Database>& dbList); // Fonction ajoutée pour mettre à jour le listWidget

private:
    Ui::ProfilPage *ui;
    Profil *profil;
    Database *newdbt;
};

#endif // PROFILPAGE_H
