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
    QString login = lineEditLogin->text();
    QString password = lineEditPassword->text();
    emit connexionClicked(login, password);
}
