// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginpage.h"
#include "profillist.h"
#include "data.h"
#include "firstconnexion.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onConnexionClicked(const QString& login, const QString& password);

private:
    LoginPage *loginPage;
    ProfilList *profilListPage;
    FirstConnexion *firstConnexion;
};

#endif // MAINWINDOW_H
