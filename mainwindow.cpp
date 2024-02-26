// mainwindow.cpp
#include "mainwindow.h"
#include "user.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    std::vector<User> userList = Data::getInstance()->getUserList();
    if (userList.size() <= 1) {
        // Si la liste est vide, afficher la page de première connexion
        firstConnexion = new FirstConnexion(this);
        setCentralWidget(firstConnexion);
    } else {
        // Sinon, afficher la page de connexion normale
        loginPage = new LoginPage(this);
        connect(loginPage, &LoginPage::connexionClicked, this, &MainWindow::onConnexionClicked);
        setCentralWidget(loginPage);
    }

    setWindowTitle("Application de Connexion");
    setGeometry(300, 300, 400, 200);
}

void MainWindow::onConnexionClicked(const QString& login, const QString& password)
{
    // Faire la connexion réussie et obtenir les données de profil, ici on suppose que la connexion est réussie
    std::vector<User> UserList = Data::getInstance()->getUserList();
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
        profilListPage = new ProfilList(this);
        profilListPage->updateTextBrowser(UserList[cont].getProfilList());
        profilListPage->updateComboBox(UserList[cont].getProfilList());
    }
    setCentralWidget(profilListPage);
}
