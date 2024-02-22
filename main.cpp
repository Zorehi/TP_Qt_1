#include <QApplication>
#include "data.h"
#include "parserjson.h"
#include "mainwindow.h"
#include <fstream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Data::setUserList(ParserJSON::parseJsonFile("userdata.json"));

    MainWindow mainWindow;
    mainWindow.show();

    std::vector<User> userList = Data::getUserList();
    std::ofstream outFile("userdata.json");
    outFile << "[ ";
    for (int i = 0; i < userList.size(); i++) {
        outFile << userList[i];
        if (i < userList.size() - 1) outFile << ", ";
        else outFile << " ";
    }
    outFile << " ]";
    outFile.close();

    return app.exec();
}
