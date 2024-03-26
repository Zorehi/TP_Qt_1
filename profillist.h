#ifndef PROFILLIST_H
#define PROFILLIST_H

#include "profil.h"
#include <QMainWindow>
#include "profilpage.h"

namespace Ui {
class ProfilList;
}

class ProfilList : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilList(std::vector<Profil>&, QWidget *parent = nullptr);
    ~ProfilList();
public slots:
    void updateTextBrowser(const std::vector<Profil>& profilList);
    void updateComboBox(const std::vector<Profil>& profilList);
    void onDeconnexionClicked(); // Déclaration de la fonction de déconnexion
    void onChangeClicked();

private:
    Ui::ProfilList *ui;
    std::vector<Profil>& profilList;
    const Profil* profilFound;
};

#endif // PROFILLIST_H
