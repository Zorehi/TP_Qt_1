#include "loginpage.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent) {
    QLabel *labelLogin = new QLabel("Login:");
    QLabel *labelPassword = new QLabel("Password:");

    lineEditLogin = new QLineEdit();
    lineEditPassword = new QLineEdit();
    lineEditPassword->setEchoMode(QLineEdit::Password);

    QPushButton *btnConnexion = new QPushButton("Connexion");
    connect(btnConnexion, &QPushButton::clicked, this, &LoginPage::onConnexionClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(labelLogin);
    layout->addWidget(lineEditLogin);
    layout->addWidget(labelPassword);
    layout->addWidget(lineEditPassword);
    layout->addWidget(btnConnexion);
}

void LoginPage::onConnexionClicked() {
    // Logique de traitement lors du clic sur le bouton "Connexion"
    // Vous pouvez ajouter ici le code nécessaire pour gérer la connexion

    // Émettre le signal pour informer MainWindow que le bouton "Connexion" a été cliqué
    emit connexionClicked();
}
