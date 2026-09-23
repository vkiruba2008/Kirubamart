#pragma once

#include "../model/User.h"
#include <string>

class UserRepository
{
public:
    bool createUser(const User& user);
    bool findByEmail(const std::string& email, User& user);
};