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
