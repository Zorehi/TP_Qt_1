#ifndef DROITS_H
#define DROITS_H

#include <string>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonValue>

class Droits
{
private:
    std::string name;

public:
    /**
     * @brief Constructeur par défaut de la classe Droits.
     */
    Droits();

    /**
     * @brief Constructeur avec initialisation du nom du droit.
     * @param _name Nom du droit.
     */
    Droits(const std::string& _name);

    /**
     * @brief Getter pour le nom du droit.
     * @return Nom du droit.
     */
    std::string getName() const;

    /**
     * @brief Setter pour le nom du droit.
     * @param newName Nouveau nom du droit.
     */
    void setName(const std::string& newName);

    /**
     * @brief Convertit l'instance de Droits en objet JSON.
     * @return Objet JSON représentant l'instance de Droits.
     */
    QJsonObject toQJsonObject() const;

    /**
     * @brief Initialise une instance de Droits à partir d'un objet JSON.
     * @param jsonObject Objet JSON à partir duquel initialiser l'instance de Droits.
     * @return Instance de Droits initialisée.
     */
    static Droits fromQJsonObject(QJsonObject jsonObject);
};

#endif // DROITS_H
