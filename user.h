#ifndef USER_H
#define USER_H


#include "profil.h"
#include "droits.h"
#include <iostream>
#include <string>
#include <vector>

class User
{
private:
    std::string username;
    std::string password;
    Droits droits;
    std::vector<Profil> profilList;

public:
    User();
    User(const std::string& name, const std::string& pass, const Droits& droits);

    /**
     * @brief getUsername getter pour le nom de l'utilisateur
     * @return std::string
     */
    std::string getUsername() const;

    /**
     * @brief setUsername setter pour le nom de l'utilisateur
     * @param newUsername std::string
     */
    void setUsername(const std::string& newUsername);

    /**
     * @brief getPassword getter pour le mot de passe de l'utilisateur
     * @return std::string
     */
    std::string getPassword() const;

    /**
     * @brief setPassword setter pour le mot de passe de l'utilisateur
     * @param newPassword std::string
     */
    void setPassword(const std::string& newPassword);

    /**
     * @brief getDroits getter pour les droits de l'utilisateur
     * @return Droits
     */
    Droits getDroits() const;

    /**
     * @brief setDroits setter pour les droits de l'utilisateur
     * @param newDroits Droits
     */
    void setDroits(const Droits& newDroits);

    /**
     * @brief getProfilList getter pour les profils de l'utilisateur
     * @return std::vector<Profil>
     */
    std::vector<Profil> getProfilList() const;

    /**
     * @brief setProfilList setter pour les profils de l'utilisateur
     * @param newProfilList std::vector<Profil>
     */
    void setProfilList(const std::vector<Profil>& newProfilList);

    /**
     * @brief operator << permet de serializer la classe User
     * @param os std::ostream
     * @param user User
     * @return std::ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    /**
     * @brief operator >> permet de créer la classe User a partir d'un stream d'une chaine de caractère
     * @param is std::istream
     * @param user User
     * @return std::istream
     */
    friend std::istream& operator>>(std::istream& is, User& user);

};

#endif // USER_H
