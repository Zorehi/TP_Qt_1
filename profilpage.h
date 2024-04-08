#ifndef PROFILPAGE_H
#define PROFILPAGE_H

#include "user.h"
#include "database.h"
#include <QWidget>
#include <QString>

namespace Ui {
class ProfilPage;
}

/**
 * @brief La classe ProfilPage fournit une interface pour afficher le profil d'un utilisateur.
 */
class ProfilPage : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe ProfilPage.
     * @param user Référence vers l'objet User associé.
     * @param profil Référence vers l'objet Profil associé.
     * @param parent Pointeur vers le widget parent.
     */
    explicit ProfilPage(User& user, Profil& profil, QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ProfilPage.
     */
    ~ProfilPage();

private slots:
    /**
     * @brief Slot pour afficher la liste des tables.
     */
    void showListTable();

    /**
     * @brief Slot pour ouvrir une boîte de dialogue de fichier.
     */
    void openFileDialog();

protected:

    /**
     * @brief Méthode pour mettre à jour le listWidget avec la liste de bases de données.
     * @param dbList La liste des bases de données à afficher.
     */
    void updateListWidget(const std::vector<Database>& dbList);

private:
    /**
     * @brief Pointeur vers l'interface utilisateur de la classe ProfilPage.
     */
    Ui::ProfilPage *ui;

    /**
     * @brief Référence à l'objet Profil utilisé par cette classe.
     */
    Profil& profil;

    /**
     * @brief Référence à l'objet User utilisé par cette classe.
     */
    User& user;
};

#endif // PROFILPAGE_H
