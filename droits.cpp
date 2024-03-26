#include "droits.h"

Droits::Droits() : name("no rights"), read(false), write(false), modify(false) {}

Droits::Droits(const std::string& _name, const bool read, const bool write, const bool modify) : name(_name), read(read), write(write), modify(modify) {}

std::string Droits::getName() const {
    return name;
}

bool Droits::hasReadable() const {
    return read;
}

bool Droits::hasWritable() const{
    return write;
}

bool Droits::hasModify() const{
    return modify;
}

void Droits::setName(const std::string& newName) {
    name = newName;
}

void Droits::setReadable(const bool _read) {
    read = _read;
}

void Droits::setWritable(const bool _write) {
    write = _write;
}

void Droits::setModify(const bool _modify) {
    modify = _modify;
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
    jsonObject["read"] = hasReadable();
    jsonObject["write"] = hasWritable();
    jsonObject["modify"] = hasModify();

    return jsonObject;
}

Droits Droits::fromQJsonObject(QJsonObject jsonObject) {
    std::string name = jsonObject["name"].toString().toStdString();
    bool read = jsonObject["read"].toBool();
    bool write = jsonObject["write"].toBool();
    bool modify = jsonObject["modify"].toBool();

    Droits droits(name, read, write, modify);

    return droits;
}
