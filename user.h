#ifndef USER_H
#define USER_H

#include "profil.h"
#include "droits.h"
#include <iostream>
#include <string>
#include <vector>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonValue>

class User
{
private:
    std::string username;       // Nom d'utilisateur
    std::string password;       // Mot de passe
    Droits droits;              // Droits de l'utilisateur
    std::vector<Profil> profilList; // Liste des profils de l'utilisateur

public:
    /**
     * @brief Constructeur par défaut de la classe User.
     */
    User();

    /**
     * @brief Constructeur avec initialisation des attributs de la classe User.
     * @param name Nom d'utilisateur.
     * @param pass Mot de passe.
     * @param droits Droits de l'utilisateur.
     */
    User(const std::string& name, const std::string& pass, const Droits& droits);

    /**
     * @brief Getter pour le nom d'utilisateur.
     * @return Nom d'utilisateur.
     */
    std::string getUsername() const;

    /**
     * @brief Setter pour le nom d'utilisateur.
     * @param newUsername Nouveau nom d'utilisateur.
     */
    void setUsername(const std::string& newUsername);

    /**
     * @brief Getter pour le mot de passe.
     * @return Mot de passe.
     */
    std::string getPassword() const;

    /**
     * @brief Setter pour le mot de passe.
     * @param newPassword Nouveau mot de passe.
     */
    void setPassword(const std::string& newPassword);

    /**
     * @brief Getter pour les droits de l'utilisateur.
     * @return Droits de l'utilisateur.
     */
    Droits& getDroits();

    /**
     * @brief Getter pour les droits de l'utilisateur. (const)
     * @return Droits de l'utilisateur. (const)
     */
    const Droits& getDroits() const;

    /**
     * @brief Setter pour les droits de l'utilisateur.
     * @param newDroits Nouveaux droits de l'utilisateur.
     */
    void setDroits(const Droits& newDroits);

    /**
     * @brief Getter pour la liste des profils de l'utilisateur.
     * @return Liste des profils de l'utilisateur.
     */
    std::vector<Profil>& getProfilList();

    /**
     * @brief Getter pour la liste des profils de l'utilisateur. (const)
     * @return Liste des profils de l'utilisateur. (const)
     */
    const std::vector<Profil>& getProfilList() const;

    /**
     * @brief Setter pour la liste des profils de l'utilisateur.
     * @param newProfilList Nouvelle liste des profils de l'utilisateur.
     */
    void setProfilList(const std::vector<Profil>& newProfilList);

    /**
     * @brief Surcharge de l'opérateur << pour sérialiser la classe User.
     * @param os Flux de sortie.
     * @param user Instance de User à sérialiser.
     * @return Référence vers le flux de sortie.
     */
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    /**
     * @brief Convertit l'instance de User en objet JSON.
     * @return Objet JSON représentant l'instance de User.
     */
    QJsonObject toQJsonObject() const;

    /**
     * @brief Initialise une instance de User à partir d'un objet JSON.
     * @param jsonObject Objet JSON à partir duquel initialiser l'instance de User.
     * @return Instance de User initialisée.
     */
    static User fromQJsonObject(QJsonObject jsonObject);
};

#endif // USER_H
