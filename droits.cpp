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
    os << "{ \"name\": \"" << droits.name << "\" }";
    return os;
}

std::istream& operator>>(std::istream& is, Droits& droits) {
    return is;
}
