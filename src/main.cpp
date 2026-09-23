#include <cstdlib>
#include <iostream>
#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>

int main()
{
    const char* connectionString = std::getenv("KIRUBAMART_DB_URL");

    if (!connectionString)
    {
        std::cerr << "KIRUBAMART_DB_URL is not set.\n";
        return 1;
    }

    auto dbClient =
        drogon::orm::DbClient::newPgClient(connectionString, 1);

    std::cout << "Database client created successfully!\n";

    drogon::app().registerHandler(
        "/",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback)
        {
            auto response = drogon::HttpResponse::newHttpResponse();
            response->setBody("Welcome to KirubaMart!");
            callback(response);
        });

    drogon::app().addListener("127.0.0.1", 8080);
    drogon::app().run();

    return 0;
}