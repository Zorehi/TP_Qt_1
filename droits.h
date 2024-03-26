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
    bool read;
    bool write;
    bool modify;

public:
    /**
     * @brief Constructeur par défaut de la classe Droits.
     */
    Droits();

    /**
     * @brief Constructeur avec initialisation du nom du droit.
     * @param _name Nom du droit.
     */
    Droits(const std::string& _name, const bool read, const bool write, const bool modify);

    /**
     * @brief Getter pour le droit de lecture.
     * @return Nom du droit.
     */
    bool hasReadable() const;

    /**
     * @brief Getter pour le droit d'écriture.
     * @return Nom du droit.
     */
    bool hasWritable() const;

    /**
     * @brief Getter pour le droit de modification.
     * @return Nom du droit.
     */
    bool hasModify() const;

    /**
     * @brief Getter pour le nom du droit.
     * @return Nom du droit.
     */
    std::string getName() const;

    /**
     * @brief Setter pour le droit de lecture.
     * @param newName Nouveau droit.
     */
    void setReadable(const bool _read);

    /**
     * @brief Setter pour le droit d'écriture.
     * @param _read Nouveau droit.
     */
    void setWritable(const bool _write);

    /**
     * @brief Setter pour le droit de modification.
     * @param _write Nouveau droit.
     */
    void setModify(const bool _modify);

    /**
     * @brief Setter pour le nom du droit.
     * @param _modify Nouveau nom du droit.
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
