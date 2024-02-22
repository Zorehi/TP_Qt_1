#include "parserjson.h"
#include "qdebug.h"
#include "qlogging.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

std::vector<User> ParserJSON::parseJsonFile(const std::string& filename) {
    QFile jsonFile("userdata.json");
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Impossible d'ouvrir le fichier JSON.";
        return std::vector<User>(0);
    }

    // Lire le contenu du fichier JSON
    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    // Analyser le contenu JSON
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Erreur de parsing JSON :" << parseError.errorString();
        return std::vector<User>(0);
    }

    // Vérifier si le document JSON est un tableau
        if (!jsonDoc.isArray()) {
        qWarning() << "Le document JSON n'est pas un tableau.";
        return std::vector<User>(0);
    }

    // Obtenir le tableau JSON
    QJsonArray jsonArray = jsonDoc.array();

    std::vector<User> userList(jsonArray.size());
    // Parcourir les éléments du tableau
    for (int i = 0; i < jsonArray.size(); ++i) {
        // Extraire les données nécessaires de chaque élément du tableau
        QJsonObject jsonObj = jsonArray[i].toObject();
        QString username = jsonObj["username"].toString();
        QString password = jsonObj["password"].toString();
        QString droitsName = jsonObj["droits"].toObject()["name"].toString();
        QJsonArray profilArray = jsonObj["profilList"].toArray();

        std::vector<Profil> profilVector(profilArray.size());
        for (int j = 0; j < profilArray.size(); j++) {
            profilVector[j] = Profil(profilArray[j].toObject()["name"].toString().toStdString());
        }

        userList[i] = User(username.toStdString(), password.toStdString(), Droits(droitsName.toStdString()));
        userList[i].setProfilList(profilVector);
    }

    return userList;
}

