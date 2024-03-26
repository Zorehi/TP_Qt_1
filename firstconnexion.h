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

class FirstConnexion : public QWidget
{
    Q_OBJECT

public:
    explicit FirstConnexion(QWidget *parent = nullptr);
    ~FirstConnexion();

private slots:
    void onPushButtonClicked(); // Slot pour gérer le clic sur le bouton "Créer un compte"

private:
    Ui::FirstConnexion *ui;
};

#endif // FIRSTCONNEXION_H
