#ifndef USER_H
#define USER_H


#include "profil.h"
#include "droits.h"
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

};

#endif // USER_H
