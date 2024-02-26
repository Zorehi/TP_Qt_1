#include <QApplication>
#include "data.h"
#include "parserjson.h"
#include "mainwindow.h"
#include <fstream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QJsonObject jsonObject = ParserJSON::parseJsonFile("userdata.json");
    Data::getInstance()->initFromQJsonObject(jsonObject);
    std::vector<User>& userList = Data::getInstance()->getUserList();
    if (userList.empty()) {
        User user = User("superadmin", "password", Droits("superadmin"));
        user.getProfilList().push_back(Profil("default"));
        userList.push_back(user);
    }

    MainWindow mainWindow;
    mainWindow.show();

    std::ofstream outFile("userdata.json");
    outFile << *Data::getInstance();
    outFile.close();

    return app.exec();
}
