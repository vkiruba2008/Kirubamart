#include <iostream>
#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>
int main()
{
    auto dbClient = drogon::orm::DbClient::newPgClient(
   "host=localhost port=5432 dbname=kirubamart user=postgres password=YOUR_PASSWORD",
    1
);

std::cout << "Database client created successfully!" << std::endl;
    drogon::app().registerHandler(
        "/",
        [](const drogon::HttpRequestPtr&,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback)
        {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("Welcome to KirubaMart!");
            callback(resp);
        });

    drogon::app().addListener("127.0.0.1", 8080);
    drogon::app().run();

    return 0;
}