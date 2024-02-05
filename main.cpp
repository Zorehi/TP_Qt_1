#include <QApplication>
#include "mainwindow.h"
#include "user.h"
#include <fstream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    User user("jeremy", "123", *new Droits("superadmin"));
    std::vector<Profil> profilList(10);
    for (auto& profil : profilList) {
        profil.setName("coucou");
    }
    user.setProfilList(profilList);

    std::ofstream outFile("userdata.json");
    outFile << user;
    outFile.close();

    return app.exec();
}
