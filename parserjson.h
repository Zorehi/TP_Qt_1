#ifndef PARSERJSON_H
#define PARSERJSON_H

#include "user.h"
#include <string>

class ParserJSON
{
public:
    static std::vector<User> parseJsonFile(const std::string& filename);
};

#endif // PARSERJSON_H
