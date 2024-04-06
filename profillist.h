#ifndef PROFILLIST_H
#define PROFILLIST_H

#include "user.h"
#include <QMainWindow>

namespace Ui {
class ProfilList;
}

class ProfilList : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilList(User& user, QWidget *parent = nullptr);
    ~ProfilList();
public slots:
    void onDeconnexionClicked(); // Déclaration de la fonction de déconnexion
    void onChangeClicked();

private:
    Ui::ProfilList *ui;
    User& user;
    const Profil* profilFound;
};

#endif // PROFILLIST_H
