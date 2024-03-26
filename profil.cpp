#include "profil.h"

Profil::Profil() : name("user"), dbList(std::vector<Database>(0)) {}

Profil::Profil(const std::string& _name) : name(_name), dbList(std::vector<Database>(0)) {}

std::string Profil::getName() const {
    return name;
}

std::vector<Database>& Profil::getDbList() {
    return dbList;
}

const std::vector<Database>& Profil::getDbList() const {
    return dbList;
}

void Profil::setName(const std::string& newName) {
    name = newName;
}

void Profil::setDbList(const std::vector<Database>& newDbList) {
    dbList = newDbList;
}

std::ostream& operator<<(std::ostream& os, const Profil& profil) {
    QJsonDocument jsonDocument(profil.toQJsonObject());

    QString jsonString = jsonDocument.toJson(QJsonDocument::Indented);

    os << jsonString.toStdString();

    return os;
}

QJsonObject Profil::toQJsonObject() const {
    QJsonObject jsonObject;
    jsonObject["name"] = QString::fromStdString(getName());

    QJsonArray jsonArray;
    for (const Database &db : getDbList()) {
        jsonArray.append(db.toQJsonObject());
    }
    jsonObject["dbList"] = jsonArray;

    return jsonObject;
}

Profil Profil::fromQJsonObject(QJsonObject jsonObject) {
    std::string name = jsonObject["name"].toString().toStdString();

    QJsonArray jsonArray = jsonObject["dbList"].toArray();
    std::vector<Database> dbList;
    for (const auto &profilJson : jsonArray) {
        dbList.push_back(Database::fromQJsonObject(profilJson.toObject()));
    }

    Profil profil;
    profil.setName(name);
    profil.setDbList(dbList);

    return profil;
}
