#ifndef PROFILLIST_H
#define PROFILLIST_H

#include "profil.h"
#include <QMainWindow>

namespace Ui {
class ProfilList;
}

class ProfilList : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProfilList(QWidget *parent = nullptr);

public slots:
    void updateTextBrowser(const std::vector<Profil>& profilList);
    void updateComboBox(const std::vector<Profil>& profilList);
    void onDeconnexionClicked(); // Déclaration de la fonction de déconnexion

private:
    Ui::ProfilList *ui;
};

#endif // PROFILLIST_H