// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginpage.h"
#include "profillist.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onConnexionClicked();

private:
    LoginPage *loginPage;
    ProfilList *profilListPage;
};

#endif // MAINWINDOW_H
