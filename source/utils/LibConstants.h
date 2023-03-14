//
// Created by asman on 10-03-2023.
//
#include <iostream>
#pragma once
#ifndef CODINGVEDA_BACKEND_CPP_SERVERCONSTANTS_H
#define CODINGVEDA_BACKEND_CPP_SERVERCONSTANTS_H

namespace LibConstants {
    namespace Project {
        const auto name = "CodingVeda";
        const auto domain = "condingveda.in";
        const auto isInDevelopment = true;
    }
    /**
     * Server Configurations
     */
     namespace Server {
         const auto host = "127.0.0.1";
         const auto port = 3001;
         const auto uploadFolder = "./uploads";
         const auto logFolder = "./logs";
         const auto name = "asman/1.0.1";
     }
    /**
     * Database Configurations
     */
     namespace Database {
         const auto dbType = "mysql";
         const auto dbHost = "127.0.0.1";
         const auto dbPort = 3306;
         const auto dbName = "codingVeda";
         const auto dbUserName = "root";
         const auto dbPassword = "";
         const auto dbConnections = 1;
     }
    /**
     * SMTP Configurations
     */
     namespace SMTP {
         const auto smtpHost = "smtp.gmail.com";
         const auto smtpPort = 465;
         const auto smtpUser = "";
         const auto smtpPass = "";
         const auto smtpSender = "admin@condingveda.in";
     }
}

#endif //CODINGVEDA_BACKEND_CPP_SERVERCONSTANTS_H
