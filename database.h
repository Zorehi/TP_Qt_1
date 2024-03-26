#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonValue>

class Database
{
private:
    std::string path;

public:
    /**
     * @brief Constructeur par défaut de la classe Database.
     */
    Database();

    /**
     * @brief Constructeur avec initialisation du chemin de la base de données.
     * @param _path Chemin de la base de données.
     */
    Database(const std::string& _path);

    /**
     * @brief Getter pour le chemin de la base de données.
     * @return Chemin de la base de données.
     */
    std::string getPath() const;

    /**
     * @brief Setter pour le chemin de la base de données.
     * @param newPath Nouveau chemin de la base de données.
     */
    void setPath(const std::string& newPath);

    /**
     * @brief Surcharge de l'opérateur << pour sérialiser la classe Database.
     * @param os Flux de sortie.
     * @param profil Instance de Database à sérialiser.
     * @return Référence vers le flux de sortie.
     */
    friend std::ostream& operator<<(std::ostream& os, const Database& db);

    /**
     * @brief Convertit l'instance de Database en objet JSON.
     * @return Objet JSON représentant l'instance de Database.
     */
    QJsonObject toQJsonObject() const;

    /**
     * @brief Initialise une instance de Database à partir d'un objet JSON.
     * @param jsonObject Objet JSON à partir duquel initialiser l'instance de Database.
     * @return Instance de Database initialisée.
     */
    static Database fromQJsonObject(QJsonObject jsonObject);
};

#endif // DATABASE_H
