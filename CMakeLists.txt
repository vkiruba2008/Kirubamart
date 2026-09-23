cmake_minimum_required(VERSION 3.25)

project(KirubaMart LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Drogon CONFIG REQUIRED)
find_package(PostgreSQL REQUIRED)
find_path(SODIUM_INCLUDE_DIR sodium.h
    PATHS "${CMAKE_SOURCE_DIR}/../vcpkg_installed/x64-windows/include"
)

find_library(SODIUM_LIBRARY sodium
    PATHS "${CMAKE_SOURCE_DIR}/../vcpkg_installed/x64-windows/lib"
)

add_executable(KirubaMart
    src/main.cpp
    src/service/AuthService.cpp
    src/controller/AuthController.cpp
    src/repository/UserRepository.cpp
)

target_include_directories(KirubaMart PRIVATE
    ${SODIUM_INCLUDE_DIR}
)

target_link_libraries(KirubaMart PRIVATE
    Drogon::Drogon
    PostgreSQL::PostgreSQL
    ${SODIUM_LIBRARY}
)