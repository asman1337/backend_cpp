//
// Created by asman on 12-03-2023.
//

#pragma once
#include <drogon/HttpController.h>
#include "../../models/Users.h"

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::codingVeda;

namespace v1 {
    class Auth : public drogon::HttpController<Auth> {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Auth::loginUser, "/login", Post, Options);
            METHOD_ADD(Auth::registerUser, "/register", Post, Options);
        METHOD_LIST_END

        void loginUser(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback, Users &&pUser) const;
        void registerUser(const HttpRequestPtr &req,std::function<void(const HttpResponsePtr &)> &&callback, Users &&pUser) const;

    private:
        struct UserWithToken {
            std::string username;
            std::string password;
            std::string token;
            explicit UserWithToken(const Users &user);
            Json::Value toJson();
        };

        bool areFieldsValid(const Users &user) const;
        bool isUserAvailable(const Users &user, Mapper<Users> &mp) const;
        bool isPasswordValid(const std::string &text, const std::string &hash) const;
    };
}
