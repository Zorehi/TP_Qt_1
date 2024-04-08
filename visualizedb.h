#ifndef VISUALIZEDB_H
#define VISUALIZEDB_H

#include <QtSql>
#include <QListWidget>
#include "database.h"
#include "user.h"

namespace Ui {
class VisualizeDb;
}

/**
 * @brief La classe VisualizeDb fournit une interface pour visualiser et manipuler les données de la base de données.
 */
class VisualizeDb : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe VisualizeDb.
     * @param user Référence vers l'objet User associé.
     * @param profil Référence vers l'objet Profil associé.
     * @param database Référence vers l'objet Database utilisé.
     * @param parent Pointeur vers le widget parent.
     */
    explicit VisualizeDb(User& user, Profil& profil, Database& database, QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe VisualizeDb.
     */
    ~VisualizeDb();

private slots:
    /**
     * @brief Slot pour afficher une table lorsqu'un élément de la liste est sélectionné.
     * @param item L'élément de la liste sélectionné.
     */
    void showTable(QListWidgetItem* item);

    /**
     * @brief Slot pour gérer le clic sur le bouton de retour.
     */
    void onClickRetour();

    /**
     * @brief Slot pour gérer le clic sur le bouton d'ajout.
     */
    void onClickAdd();

    /**
     * @brief Slot pour gérer le clic sur le bouton de suppression.
     */
    void onClickDelete();

    /**
     * @brief Slot pour gérer le clic sur le bouton SQL.
     */
    void onClickSQLButton();

private:
    /**
     * @brief Pointeur vers l'interface utilisateur de la classe VisualizeDb.
     */
    Ui::VisualizeDb *ui;

    /**
     * @brief Référence à l'objet Database utilisé par cette classe.
     */
    Database& database;

    /**
     * @brief Référence à l'objet Profil utilisé par cette classe.
     */
    Profil& profil;

    /**
     * @brief Référence à l'objet User utilisé par cette classe.
     */
    User& user;

    // Constructeur par copie supprimé pour empêcher la duplication de l'instance.
    VisualizeDb(const VisualizeDb&) = delete;
    // Opérateur d'assignation par copie supprimé pour empêcher la duplication de l'instance.
    VisualizeDb& operator=(const VisualizeDb&) = delete;
};

#endif // VISUALIZEDB_H
