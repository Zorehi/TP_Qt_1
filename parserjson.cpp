#include "parserjson.h"

QJsonObject ParserJSON::parseJsonFile(const std::string& filename) {
    QFile jsonFile("userdata.json");
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Impossible d'ouvrir le fichier JSON.";
        return QJsonObject();
    }

    // Lire le contenu du fichier JSON
    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    // Analyser le contenu JSON
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Erreur de parsing JSON :" << parseError.errorString();
        return QJsonObject();
    }

    // Vérifier si le document JSON est un objet
    if (!jsonDoc.isObject()) {
        qWarning() << "Le document JSON n'est pas un objet.";
        return QJsonObject();
    }

    return jsonDoc.object();
}

