#include "profil.h"

Profil::Profil() {}

Profil::Profil(const std::string& _name) : name(_name) {}

std::string Profil::getName() const {
    return name;
}

void Profil::setName(const std::string& newName) {
    name = newName;
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

    return jsonObject;
}

Profil Profil::fromQJsonObject(QJsonObject jsonObject) {
    std::string name = jsonObject["name"].toString().toStdString();

    Profil profil;
    profil.setName(name);

    return profil;
}
