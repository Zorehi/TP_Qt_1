#ifndef DROITS_H
#define DROITS_H

#include <iostream>
#include <string>

class Droits
{
private:
    std::string name;

public:
    Droits();
    Droits(const std::string& _name);

    /**
     * @brief getName getter pour le nom du droits
     * @return std::string
     */
    std::string getName() const;

    /**
     * @brief setName setter pour le nom du droits
     * @param newName std::string
     */
    void setName(const std::string& newName);

    /**
     * @brief operator << permet de serializer la classe Droits
     * @param os std::ostream
     * @param droits Droits
     * @return std::ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const Droits& droits);

    /**
     * @brief operator >> permet de créer la classe Droits a partir d'un stream d'une chaine de caractère
     * @param is std::istream
     * @param droits Droits
     * @return std::istream
     */
    friend std::istream& operator>>(std::istream& is, Droits& droits);
};

#endif // DROITS_H
