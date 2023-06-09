#include <iostream>
#include <filesystem>
#include <drogon/drogon.h>

#include "utils/LibConstants.h"
#include "utils/LibHelpers.h"

void initServerRequirements();

int main() {
    initServerRequirements();
    //opted for std::cout instead of combining with std::format to avoid error while using g++-12
    std::cout << "- " << LibConstants::Project::name << " Server is now running ..." << std::endl;
    std::cout << "- Live at http://" << LibConstants::Server::host << ":" << LibConstants::Server::port << std::endl;
    std::cout << "- Using " << LibHelpers::getThreadsForServer() << " threads." << std::endl;

    /**
     * Configuring Database
     */
    drogon::app().createDbClient(
            LibConstants::Database::dbType,
            LibConstants::Database::dbHost,
            LibConstants::Database::dbPort,
            LibConstants::Database::dbName,
            LibConstants::Database::dbUserName,
            LibConstants::Database::dbPassword,
            LibConstants::Database::dbConnections);
    /**
     * Configuring Server
     */
    drogon::app()
            .setupFileLogger()
            .setLogPath("./logs")
            .setLogLevel(trantor::Logger::kError)
            .setUploadPath("./uploads")
            .enableGzip(true)
            .setServerHeaderField(LibConstants::Server::name)
            .addListener(LibConstants::Server::host, LibConstants::Server::port)
            .registerHandler("/", [](
                    const drogon::HttpRequestPtr &req,
                    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
                auto resp = drogon::HttpResponse::newHttpResponse();
                resp->setBody("We ♥ C++");
                callback(resp);
            })
            .setThreadNum(LibHelpers::getThreadsForServer())
            .run();

    return EXIT_SUCCESS;
}

void initServerRequirements() {
    if (!std::filesystem::exists(LibConstants::Server::logFolder))
        std::filesystem::create_directory(LibConstants::Server::logFolder);

    if (!std::filesystem::exists(LibConstants::Server::uploadFolder))
        std::filesystem::create_directory(LibConstants::Server::uploadFolder);
}