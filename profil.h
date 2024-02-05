#ifndef PROFIL_H
#define PROFIL_H

#include <string>
#include <iostream>

class Profil
{
private:
    std::string name;

public:
    Profil();
    Profil(const std::string& _name);

    /**
     * @brief getName getter pour le nom du profil
     * @return std::string
     */
    std::string getName() const;

    /**
     * @brief setName setter pour le nom du profil
     * @param newName std::string
     */
    void setName(const std::string& newName);

    /**
     * @brief operator << permet de serializer la classe Profil
     * @param os std::ostream
     * @param profil Profil
     * @return std::ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const Profil& profil);

    /**
     * @brief operator >> permet de créer la classe Profil a partir d'un stream d'une chaine de caractère
     * @param is std::istream
     * @param profil Profil
     * @return std::istream
     */
    friend std::istream& operator>>(std::istream& is, Profil& profil);
};

#endif // PROFIL_H
