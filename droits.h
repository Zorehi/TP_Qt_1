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
    bool create;
    bool read;
    bool update;
    bool _delete;

public:
    /**
     * @brief Constructeur par défaut de la classe Droits.
     */
    Droits();

    /**
     * @brief Constructeur avec initialisation du nom du droit.
     * @param _name Nom du droit.
     */
    Droits(const bool create, const bool read, const bool update, const bool _delete);

    /**
     * @brief Getter pour le droit de lecture.
     * @return Nom du droit.
     */
    bool hasRead() const;

    /**
     * @brief Getter pour le droit de création.
     * @return Nom du droit.
     */
    bool hasCreate() const;

    /**
     * @brief Getter pour le droit de modification.
     * @return Nom du droit.
     */
    bool hasUpdate() const;

    /**
     * @brief Getter pour le droit de modification.
     * @return Nom du droit.
     */
    bool hasDelete() const;

    /**
     * @brief Setter pour le droit de lecture.
     * @param newName Nouveau droit.
     */
    void setRead(const bool _read);

    /**
     * @brief Setter pour le droit de création.
     * @param _read Nouveau droit.
     */
    void setCreate(const bool _create);

    /**
     * @brief Setter pour le droit de modification.
     * @param _write Nouveau droit.
     */
    void setUpdate(const bool _update);

    /**
     * @brief Setter pour le droit de modification.
     * @param _write Nouveau droit.
     */
    void setDelete(const bool _delete);

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
