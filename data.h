#ifndef DATA_H
#define DATA_H

#include "user.h"

class Data
{

public:
    static std::vector<User> userList;

    static std::vector<User> getUserList();
    static void setUserList(const std::vector<User>& userList);
};

#endif // DATA_H
