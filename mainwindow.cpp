// mainwindow.cpp
#include "mainwindow.h"
#include "droits.h"
#include "user.h"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    loginPage = new LoginPage(this);
    connect(loginPage, &LoginPage::connexionClicked, this, &MainWindow::onConnexionClicked);

    setCentralWidget(loginPage);
    setWindowTitle("Application de Connexion");
    setGeometry(300, 300, 400, 200);
}

void MainWindow::onConnexionClicked() {
    // Faire la connexion réussie et obtenir les données de profil, ici on suppose que la connexion est réussie
    User user("jeremy", "123", *new Droits("superadmin"));
    std::vector<Profil> profilList(10);
    for (auto& profil : profilList) {
        profil.setName("coucou");
    }
    user.setProfilList(profilList);

    std::ofstream outFile("userdata.json");
    outFile << user;
    outFile.close();

    profilListPage = new ProfilList(this);
    profilListPage->updateTextBrowser(profilList);
    profilListPage->updateComboBox(profilList);

    setCentralWidget(profilListPage);
}
