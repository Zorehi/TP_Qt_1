#ifndef FIRSTCONNEXION_H
#define FIRSTCONNEXION_H

#include <QWidget>
#include "user.h"
#include "droits.h"
#include "data.h"
#include <QMessageBox>

namespace Ui {
class FirstConnexion;
}

/**
 * @brief La classe FirstConnexion fournit une interface pour la première connexion d'un utilisateur.
 */
class FirstConnexion : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe FirstConnexion.
     * @param parent Pointeur vers le widget parent.
     */
    explicit FirstConnexion(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe FirstConnexion.
     */
    ~FirstConnexion();

private slots:
    /**
     * @brief Slot pour gérer le clic sur le bouton "Créer un compte".
     */
    void onPushButtonClicked();

private:
    /**
     * @brief Pointeur vers l'interface utilisateur de la classe FirstConnexion.
     */
    Ui::FirstConnexion *ui;
};

#endif // FIRSTCONNEXION_H
