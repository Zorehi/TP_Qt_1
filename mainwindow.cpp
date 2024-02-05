#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    loginPage = new LoginPage(this);

    // Créer la nouvelle page "Form"
    form = new Form();

    // Connecter le signal de LoginPage au slot de MainWindow
    connect(loginPage, &LoginPage::connexionClicked, this, &MainWindow::onConnexionClicked);

    // Afficher la page de connexion au départ
    setCentralWidget(loginPage);
    setWindowTitle("Application de Connexion");
    setGeometry(300, 300, 400, 200);
}

void MainWindow::onConnexionClicked() {
    // Changer de page vers la page "Form"
    setCentralWidget(form);
}
