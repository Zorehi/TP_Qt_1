// mainwindow.cpp
#include "mainwindow.h"
#include "user.h"
#include "parserjson.h"
#include <QMessageBox>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QJsonObject jsonObject = ParserJSON::parseJsonFile("userdata.json");
    Data::getInstance()->initFromQJsonObject(jsonObject);
    std::vector<User>& userList = Data::getInstance()->getUserList();
    if (userList.empty()) {
        User user = User("superadmin", "password", Droits("admin", true, true, true));
        user.getProfilList().push_back(Profil("default"));
        userList.push_back(user);
    }

    if (userList.size() <= 1) {
        // Si la liste est vide, afficher la page de première connexion
        firstConnexion = new FirstConnexion(this);
        setCentralWidget(firstConnexion);
    } else {
        // Sinon, afficher la page de connexion normale
        loginPage = new LoginPage(this);
        setCentralWidget(loginPage);
    }

    setWindowTitle("Application de Connexion");
    resize(600, 400);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // Appel de la fonction parent closeEvent pour exécuter le comportement de fermeture par défaut
    QMainWindow::closeEvent(event);

    // Enregistrer les variables dans un fichier
    std::ofstream outFile("userdata.json");
    outFile << *Data::getInstance();
    outFile.close();
}
