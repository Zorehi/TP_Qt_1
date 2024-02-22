#include "data.h"

std::vector<User> Data::userList;

std::vector<User> Data::getUserList() {
    return Data::userList;
}

void Data::setUserList(const std::vector<User>& userList) {
    Data::userList = userList;
}
