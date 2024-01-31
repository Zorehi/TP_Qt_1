#include "user.h"

User::User() {}

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
