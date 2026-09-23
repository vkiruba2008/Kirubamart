#include "UserRepository.h"

bool UserRepository::createUser(const User&)
{
    return true;
}

bool UserRepository::findByEmail(const std::string&, User&)
{
    return false;
}