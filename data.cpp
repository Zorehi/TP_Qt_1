#include "data.h"

Data::Data() {}

Data* Data::instance = nullptr;

Data* Data::getInstance() {
    if (instance == nullptr) {
        instance = new Data();
    }
    return instance;
}

std::vector<User>& Data::getUserList() {
    return userList;
}

const std::vector<User>& Data::getUserList() const {
    return userList;
}

void Data::setUserList(const std::vector<User>& userList) {
    Data::userList = userList;
}

std::ostream &operator<<(std::ostream &os, const Data& data) {
    QJsonDocument jsonDocument(data.toQJsonObject());

    QString jsonString = jsonDocument.toJson(QJsonDocument::Indented);

    os << jsonString.toStdString();

    return os;
}

QJsonObject Data::toQJsonObject() const {
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    for (const User& user : getUserList()) {
        jsonArray.append(user.toQJsonObject());
    }
    jsonObject["userList"] = jsonArray;

    return jsonObject;
}

Data* Data::initFromQJsonObject(QJsonObject jsonObject) {
    if (jsonObject.isEmpty()) {
        getInstance()->setUserList(std::vector<User>(0));
        return getInstance();
    }

    QJsonArray jsonArray = jsonObject["userList"].toArray();
    std::vector<User> userList;
    for (const auto &userJson : jsonArray) {
        userList.push_back(User::fromQJsonObject(userJson.toObject()));
    }

    getInstance()->setUserList(userList);
    return getInstance();
}
