// mainwindow.cpp
#include "mainwindow.h"
#include "user.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    loginPage = new LoginPage(this);
    connect(loginPage, &LoginPage::connexionClicked, this, &MainWindow::onConnexionClicked);

    setCentralWidget(loginPage);
    setWindowTitle("Application de Connexion");
    setGeometry(300, 300, 400, 200);
}

void MainWindow::onConnexionClicked(const QString& login, const QString& password)
{
    // Faire la connexion réussie et obtenir les données de profil, ici on suppose que la connexion est réussie
    std::vector<User> UserList = Data::getUserList();
    int cont = -1;
    for(int i = 0 ; i < UserList.size() ; i++){
        if(UserList[i].getUsername() == login.toStdString() && UserList[i].getPassword() == password.toStdString()){
            cont = i;
        }
    }
    if(cont == -1){
        QMessageBox::critical(this, "Erreur", "Identifiants incorrects. Veuillez réessayer.");
    }
    else
    {


    profilListPage = new ProfilList(this);
    profilListPage->updateTextBrowser(UserList[cont].getProfilList());
    profilListPage->updateComboBox(UserList[cont].getProfilList());
    }
    setCentralWidget(profilListPage);
}
