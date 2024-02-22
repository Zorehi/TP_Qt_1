#ifndef DATA_H
#define DATA_H

#include "user.h"

class Data
{
private:
    static std::vector<User> userList;

public:
    static std::vector<User> getUserList();
    static void setUserList(std::vector<User> userList);
};

#endif // DATA_H
