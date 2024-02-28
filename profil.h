#ifndef PROFIL_H
#define PROFIL_H

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
     * @brief Setter pour le nom du profil.
     * @param newName Nouveau nom du profil.
     */
    void setName(const std::string& newName);

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
