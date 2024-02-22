#include "data.h"

Data::Data(std::vector<User> userList) {
    this->userList = userList;
}

std::vector<User> Data::getUserList() {
    return this->userList;
}

void Data::setUserList(std::vector<User> userList) {
    this->userList = userList;
}
