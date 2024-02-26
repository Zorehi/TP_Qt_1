#include "droits.h"

Droits::Droits() {
    name = "";
}

Droits::Droits(const std::string& _name) : name(_name){}

std::string Droits::getName() const {
    return name;
}

void Droits::setName(const std::string& newName) {
    name = newName;
}

std::ostream& operator<<(std::ostream& os, const Droits& droits) {
    QJsonDocument jsonDocument(droits.toQJsonObject());

    QString jsonString = jsonDocument.toJson(QJsonDocument::Indented);

    os << jsonString.toStdString();

    return os;
}

QJsonObject Droits::toQJsonObject() const {
    QJsonObject jsonObject;
    jsonObject["name"] = QString::fromStdString(getName());

    return jsonObject;
}

Droits Droits::fromQJsonObject(QJsonObject jsonObject) {
    std::string name = jsonObject["name"].toString().toStdString();

    Droits droits;
    droits.setName(name);

    return droits;
}
