#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    loginPage = new LoginPage(this);

    // Configurer la fenêtre principale pour afficher la page de connexion
    setCentralWidget(loginPage);
    setWindowTitle("Application de Connexion");
    setGeometry(300, 300, 400, 200);
}
