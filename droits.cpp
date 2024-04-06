#include "droits.h"

Droits::Droits() : read(true), create(false), update(false), _delete(false) {}

Droits::Droits(const bool read, const bool create, const bool update, const bool _delete) : read(read), create(create), update(update), _delete(_delete) {}

bool Droits::hasRead() const {
    return read;
}

bool Droits::hasCreate() const{
    return create;
}

bool Droits::hasUpdate() const{
    return update;
}

bool Droits::hasDelete() const{
    return _delete;
}

void Droits::setRead(const bool _read) {
    read = _read;
}

void Droits::setCreate(const bool _create) {
    create = _create;
}

void Droits::setUpdate(const bool _update) {
    update = _update;
}

void Droits::setDelete(const bool _delete_) {
    _delete = _delete_;
}

std::ostream& operator<<(std::ostream& os, const Droits& droits) {
    QJsonDocument jsonDocument(droits.toQJsonObject());

    QString jsonString = jsonDocument.toJson(QJsonDocument::Indented);

    os << jsonString.toStdString();

    return os;
}

QJsonObject Droits::toQJsonObject() const {
    QJsonObject jsonObject;
    jsonObject["read"] = hasRead();
    jsonObject["create"] = hasCreate();
    jsonObject["update"] = hasUpdate();
    jsonObject["delete"] = hasDelete();

    return jsonObject;
}

Droits Droits::fromQJsonObject(QJsonObject jsonObject) {
    bool read = jsonObject["read"].toBool();
    bool create = jsonObject["create"].toBool();
    bool update = jsonObject["update"].toBool();
    bool _delete = jsonObject["delete"].toBool();

    Droits droits(read, create, update, _delete);

    return droits;
}
