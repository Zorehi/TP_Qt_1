#include "user.h"

User::User() {
    username = "";
    password = "";
    droits = Droits();
    profilList = std::vector<Profil>(0);
}

User::User(const std::string& name, const std::string& pass, const Droits& dts)
    : username(name), password(pass), droits(dts), profilList(std::vector<Profil>(0)) {};

// Implémentation des getters et setters
std::string User::getUsername() const {
    return username;
}

void User::setUsername(const std::string& newUsername) {
    username = newUsername;
}

std::string User::getPassword() const {
    return password;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}

Droits& User::getDroits() {
    return droits;
}

const Droits& User::getDroits() const {
    return droits;
}

void User::setDroits(const Droits& newDroits) {
    droits = newDroits;
}

std::vector<Profil>& User::getProfilList() {
    return profilList;
}

const std::vector<Profil>& User::getProfilList() const {
    return profilList;
}

void User::setProfilList(const std::vector<Profil>& newProfilList) {
    profilList = newProfilList;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    QJsonDocument jsonDocument(user.toQJsonObject());

    QString jsonString = jsonDocument.toJson(QJsonDocument::Indented);

    os << jsonString.toStdString();

    return os;
}

QJsonObject User::toQJsonObject() const {
    QJsonObject jsonObject;
    jsonObject["username"] = QString::fromStdString(getUsername());
    jsonObject["password"] = QString::fromStdString(getPassword());
    jsonObject["droits"] = getDroits().toQJsonObject();

    QJsonArray jsonArray;
    for (const Profil &profil : getProfilList()) {
        jsonArray.append(profil.toQJsonObject());
    }
    jsonObject["profilList"] = jsonArray;

    return jsonObject;
}

User User::fromQJsonObject(QJsonObject jsonObject) {
    std::string password = jsonObject["password"].toString().toStdString();
    std::string username = jsonObject["username"].toString().toStdString();
    Droits droits = Droits::fromQJsonObject(jsonObject["droits"].toObject());

    QJsonArray jsonArray = jsonObject["profilList"].toArray();
    std::vector<Profil> profilList;
    for (const auto &profilJson : jsonArray) {
        profilList.push_back(Profil::fromQJsonObject(profilJson.toObject()));
    }

    User user;
    user.setUsername(username);
    user.setPassword(password);
    user.setDroits(droits);
    user.setProfilList(profilList);

    return user;
}
