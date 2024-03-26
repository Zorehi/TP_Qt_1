#include "loginpage.h"
#include "mainwindow.h"
#include "profillist.h"
#include "user.h"
#include "data.h"
#include <QVBoxLayout>
#include <QMessageBox>
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

    // Faire la connexion réussie et obtenir les données de profil, ici on suppose que la connexion est réussie
    std::vector<User>& UserList = Data::getInstance()->getUserList();
    int cont = -1;
    for(int i = 0 ; i < UserList.size() ; i++){
        if(UserList[i].getUsername() == login.toStdString() && UserList[i].getPassword() == password.toStdString()){
            cont = i;
        }
    }
    if(cont == -1){
        QMessageBox::critical(this, "Erreur", "Identifiants incorrects. Veuillez réessayer.");
        return;
    }
    else
    {
        std::vector<Profil>& listProfil = UserList[cont].getProfilList();
        ProfilList* profilListPage = new ProfilList(listProfil, this);
        profilListPage->updateTextBrowser(listProfil);
        profilListPage->updateComboBox(listProfil);
        ((MainWindow*)parent())->setCentralWidget(profilListPage);
    }
}
