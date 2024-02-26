#ifndef PARSERJSON_H
#define PARSERJSON_H

#include <string>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

class ParserJSON
{
public:
    /**
     * @brief Parse le contenu d'un fichier JSON.
     * @param filename Nom du fichier JSON à parser.
     * @return Objet JSON représentant le contenu du fichier.
     */
    static QJsonObject parseJsonFile(const std::string& filename);
};

#endif // PARSERJSON_H
