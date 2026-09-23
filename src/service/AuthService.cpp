#include "AuthService.h"

AuthService::AuthService(UserRepository& userRepository)
    : userRepository(userRepository)
{
}

bool AuthService::registerUser(
    const std::string& name,
    const std::string& email,
    const std::string& password)
{
    User user;
    user.name = name;
    user.email = email;
    user.passwordHash = password;
    user.role = "BUYER";

    return userRepository.createUser(user);
}

bool AuthService::login(
    const std::string& email,
    const std::string& password)
{
    User user;

    if (!userRepository.findByEmail(email, user))
        return false;

    return user.passwordHash == password;
}