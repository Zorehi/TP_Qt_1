#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginpage.h"
#include "form.h" // Assurez-vous que vous avez inclus la classe Form

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onConnexionClicked();

private:
    LoginPage *loginPage;
    Form *form; // Nouvelle page à afficher
};

#endif // MAINWINDOW_H
