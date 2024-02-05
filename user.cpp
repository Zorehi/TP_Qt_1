#include "user.h"

User::User(const std::string& name, const std::string& pass, const Droits& dts)
    : username(name), password(pass), droits(dts) {};

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

Droits User::getDroits() const {
    return droits;
}

void User::setDroits(const Droits& newDroits) {
    droits = newDroits;
}

std::vector<Profil> User::getProfilList() const {
    return profilList;
}

void User::setProfilList(const std::vector<Profil>& newProfilList) {
    profilList = newProfilList;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "{ ";
    os << "\"username\": \"" << user.username << "\", ";
    os << "\"password\": \"" << user.password << "\", ";
    os << "\"droits\": " << user.droits << ", ";
    os << "\"profilList\": [ ";
    for (int i = 0; i < user.profilList.size(); i++) {
        os << user.profilList[i];
        if (i < user.profilList.size() - 1) os << ", ";
        else os << " ";
    }
    os << "] }";
    return os;
}
