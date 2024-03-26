#ifndef PROFIL_H
#define PROFIL_H

#include "database.h"
#include <string>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonValue>

class Profil
{
private:
    std::string name;
    std::vector<Database> dbList;

public:
    /**
     * @brief Constructeur par défaut de la classe Profil.
     */
    Profil();

    /**
     * @brief Constructeur avec initialisation du nom du profil.
     * @param _name Nom du profil.
     */
    Profil(const std::string& _name);

    /**
     * @brief Getter pour le nom du profil.
     * @return Nom du profil.
     */
    std::string getName() const;

    /**
     * @brief Getter pour la liste des bases de données.
     * @return Liste des bases de données.
     */
    std::vector<Database>& getDbList();

    /**
     * @brief Getter pour la liste des bases de données. (const)
     * @return Liste des bases de données. (const)
     */
    const std::vector<Database>& getDbList() const;

    /**
     * @brief Setter pour le nom du profil.
     * @param newName Nouveau nom du profil.
     */
    void setName(const std::string& newName);

    /**
     * @brief Setter pour la liste des profils de l'utilisateur.
     * @param newProfilList Nouvelle liste des profils de l'utilisateur.
     */
    void setDbList(const std::vector<Database>& newDbList);

    /**
     * @brief Surcharge de l'opérateur << pour sérialiser la classe Profil.
     * @param os Flux de sortie.
     * @param profil Instance de Profil à sérialiser.
     * @return Référence vers le flux de sortie.
     */
    friend std::ostream& operator<<(std::ostream& os, const Profil& profil);

    /**
     * @brief Convertit l'instance de Profil en objet JSON.
     * @return Objet JSON représentant l'instance de Profil.
     */
    QJsonObject toQJsonObject() const;

    /**
     * @brief Initialise une instance de Profil à partir d'un objet JSON.
     * @param jsonObject Objet JSON à partir duquel initialiser l'instance de Profil.
     * @return Instance de Profil initialisée.
     */
    static Profil fromQJsonObject(QJsonObject jsonObject);
};

#endif // PROFIL_H
