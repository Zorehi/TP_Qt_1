#ifndef DATA_H
#define DATA_H

#include "user.h"

class Data
{
private:
    std::vector<User> userList;

public:
    Data(std::vector<User> userList);

    std::vector<User> getUserList();
    void setUserList(std::vector<User> userList);
};

#endif // DATA_H
