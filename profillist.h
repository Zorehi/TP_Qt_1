#ifndef PROFILLIST_H
#define PROFILLIST_H

#include "user.h"
#include <QMainWindow>

namespace Ui {
class ProfilList;
}

/**
 * @brief La classe ProfilList fournit une interface pour afficher une liste de profils d'utilisateurs.
 */
class ProfilList : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe ProfilList.
     * @param user Référence vers l'objet User associé.
     * @param parent Pointeur vers le widget parent.
     */
    explicit ProfilList(User& user, QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ProfilList.
     */
    ~ProfilList();

public slots:
    /**
     * @brief Slot pour gérer le clic sur le bouton de déconnexion.
     */
    void onDeconnexionClicked();

    /**
     * @brief Slot pour gérer le clic sur le bouton de changement.
     */
    void onChangeClicked();

private:
    /**
     * @brief Pointeur vers l'interface utilisateur de la classe ProfilList.
     */
    Ui::ProfilList *ui;

    /**
     * @brief Référence à l'objet User utilisé par cette classe.
     */
    User& user;

    /**
     * @brief Pointeur constant vers le profil trouvé.
     */
    const Profil* profilFound;
};

#endif // PROFILLIST_H
