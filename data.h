#ifndef DATA_H
#define DATA_H

#include "user.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonValue>

class Data
{
private:
    std::vector<User> userList;
    static Data* instance;

    Data();

public:
    /**
     * @brief Constructeur par copie supprimé pour empêcher la duplication de l'instance.
     */
    Data(const Data&) = delete;

    /**
     * @brief Opérateur d'affectation supprimé pour empêcher la duplication de l'instance.
     */
    void operator=(const Data&) = delete;

    /**
     * @brief Renvoie l'instance unique de la classe Data.
     * @return Pointeur vers l'instance de Data.
     */
    static Data* getInstance();

    /**
     * @brief Renvoie la liste des utilisateurs.
     * @return Référence vers la liste des utilisateurs.
     */
    std::vector<User>& getUserList();

    /**
     * @brief Renvoie la liste des utilisateurs (const).
     * @return Référence constante vers la liste des utilisateurs. (const)
     */
    const std::vector<User>& getUserList() const;

    /**
     * @brief Définit la liste des utilisateurs.
     * @param userList Nouvelle liste des utilisateurs.
     */
    void setUserList(const std::vector<User>& userList);

    void addUser(const User& newUser);

    /**
     * @brief Surcharge de l'opérateur << pour sérialiser la classe Data.
     * @param os Flux de sortie.
     * @param data Instance de Data à sérialiser.
     * @return Référence vers le flux de sortie.
     */
    friend std::ostream& operator<<(std::ostream& os, const Data& data);

    /**
     * @brief Convertit l'instance de Data en objet JSON.
     * @return Objet JSON représentant l'instance de Data.
     */
    QJsonObject toQJsonObject() const;

    /**
     * @brief Initialise une instance de Data à partir d'un objet JSON.
     * @param jsonObject Objet JSON à partir duquel initialiser l'instance de Data.
     * @return Pointeur vers l'instance de Data initialisée.
     */
    static Data* initFromQJsonObject(QJsonObject jsonObject);

};

#endif // DATA_H
