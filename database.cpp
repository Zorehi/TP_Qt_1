#include "database.h"

Database::Database() {}

Database::Database(const std::string& _path) : path(_path) {}

std::string Database::getPath() const {
    return path;
}

void Database::setPath(const std::string& newPath) {
    path = newPath;
}


std::string Database::getName() const {
    return dbName;
}

void Database::setName(const std::string& newName) {
    dbName = newName;
}

std::ostream& operator<<(std::ostream& os, const Database& db) {
    QJsonDocument jsonDocument(db.toQJsonObject());

    QString jsonString = jsonDocument.toJson(QJsonDocument::Indented);

    os << jsonString.toStdString();

    return os;
}

QJsonObject Database::toQJsonObject() const {
    QJsonObject jsonObject;
    jsonObject["path"] = QString::fromStdString(getPath());

    return jsonObject;
}

Database Database::fromQJsonObject(QJsonObject jsonObject) {
    std::string path = jsonObject["path"].toString().toStdString();

    Database database;
    database.setPath(path);

    return database;
}
