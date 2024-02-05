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
    os << "{ \"name\": \"" << profil.name << "\" }";
    return os;
}
