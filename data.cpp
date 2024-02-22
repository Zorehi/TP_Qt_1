#include "data.h"

std::vector<User> Data::getUserList() {
    return Data::userList;
}

void Data::setUserList(std::vector<User> userList) {
    Data::userList = userList;
}
