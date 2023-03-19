//
// Created by asman on 12-03-2023.
//
#include <../../third_party/libbcrypt/include/bcrypt/BCrypt.hpp>
#include "Auth.h"
#include "../../plugins/JwtPlugin.h"

using namespace v1;
namespace drogon {
    template<>
    inline Users fromRequest(const HttpRequest &req) {
        auto jsonPtr = req.getJsonObject();
        auto json = *jsonPtr;
        auto user = Users(json);
        return user;
    }
}

void Auth::loginUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, Users &&pUser) const {
    LOG_DEBUG << "loginUser";
    try {
        auto dbClientPtr = drogon::app().getDbClient();
        Mapper<Users> mp(dbClientPtr);

        if (!areFieldsValid(pUser)) {
            Json::Value ret{};
            ret["error"] = "missing fields";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k400BadRequest);
            callback(resp);
            return;
        }

        auto user = mp.findFutureBy(Criteria(Users::Cols::_email, CompareOperator::EQ, pUser.getValueOfEmail())).get();
        if (user.empty()) {
            Json::Value ret{};
            ret["error"] = "user not found";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k400BadRequest);
            callback(resp);
            return;
        }

        if (!isPasswordValid(pUser.getValueOfPassword(), user[0].getValueOfPassword())) {
            Json::Value ret{};
            ret["error"] = "username and password do not match";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k401Unauthorized);
            callback(resp);
            return;
        }

        auto userWithToken = Auth::UserWithToken(user[0]);
        auto ret = userWithToken.toJson();
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        callback(resp);
    } catch (const DrogonDbException &e) {
        LOG_ERROR << e.base().what();
        Json::Value ret{};
        ret["error"] = "database error";
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(HttpStatusCode::k500InternalServerError);
        callback(resp);
    }
}

void Auth::registerUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,Users &&pUser) const {
    LOG_DEBUG << "registerUser";
    try {
        auto dbClientPtr = drogon::app().getDbClient();
        Mapper<Users> mp(dbClientPtr);

        if (!areFieldsValid(pUser)) {
            Json::Value ret{};
            ret["error"] = "missing fields";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k400BadRequest);
            callback(resp);
            return;
        }

        if (!isUserAvailable(pUser, mp)) {
            Json::Value ret{};
            ret["error"] = "username is taken";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k400BadRequest);
            callback(resp);
            return;
        }

        auto newUser = pUser;
        newUser.setPassword(BCrypt::generateHash(newUser.getValueOfPassword()));
        mp.insertFuture(newUser).get();

        auto userWithToken = Auth::UserWithToken(newUser);
        Json::Value ret = userWithToken.toJson();
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(HttpStatusCode::k201Created);
        callback(resp);
    } catch (const DrogonDbException & e) {
        LOG_ERROR << e.base().what();
        Json::Value ret{};
        ret["error"] = "database error";
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(HttpStatusCode::k500InternalServerError);
        callback(resp);
    }
}

bool Auth::areFieldsValid(const Users &user) const {
    return user.getEmail() != nullptr && user.getPassword() != nullptr;
}

bool Auth::isUserAvailable(const Users &user, Mapper<Users> &mp) const {
    auto criteria = Criteria(Users::Cols::_email, CompareOperator::EQ, user.getValueOfEmail());
    return mp.findFutureBy(criteria).get().empty();
}

bool Auth::isPasswordValid(const std::string &text, const std::string &hash) const {
    return BCrypt::validatePassword(text, hash);
}

Auth::UserWithToken::UserWithToken(const Users &user) {
    auto *jwtPtr = drogon::app().getPlugin<JwtPlugin>();
    auto jwt = jwtPtr->init();
    token = jwt.encode("user_id", user.getValueOfId());
    username = user.getValueOfEmail();
}

Json::Value Auth::UserWithToken::toJson() {
    Json::Value ret{};
    ret["username"] = username;
    ret["token"] = token;
    return ret;
}