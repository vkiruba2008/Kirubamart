#pragma once

#include <string>
#include "../repository/UserRepository.h"

class AuthService
{
private:
    UserRepository& userRepository;

public:
    AuthService(UserRepository& userRepository);

    bool registerUser(
        const std::string& name,
        const std::string& email,
        const std::string& password);

    bool login(
        const std::string& email,
        const std::string& password);
};