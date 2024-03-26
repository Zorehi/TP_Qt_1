// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginpage.h"
#include "profillist.h"
#include "firstconnexion.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr);

private:
    LoginPage *loginPage;
    ProfilList *profilListPage;
    FirstConnexion *firstConnexion;
};

#endif // MAINWINDOW_H
