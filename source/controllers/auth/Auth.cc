//
// Created by asman on 12-03-2023.
//
#include "Auth.h"

using namespace api::v1;

void Auth::loginUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, Users &&pUser) const {
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("loggedIn successfully...");
    resp->setStatusCode(HttpStatusCode::k202Accepted);
    callback(resp);
}

void Auth::registerUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, Users &&pUser) const {
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("registered successfully...");
    resp->setStatusCode(HttpStatusCode::k201Created);
    callback(resp);
}

bool Auth::areFieldsValid(const Users &user) const {
    return user.getEmail() != nullptr && user.getPassword() != nullptr;
}

bool Auth::isUserAvailable(const Users &user, Mapper<Users> &mp) const {
    auto criteria = Criteria(Users::Cols::_email, CompareOperator::EQ, user.getValueOfEmail());
    return mp.findFutureBy(criteria).get().empty();
}

bool Auth::isPasswordValid(const std::string &text, const std::string &hash) const {
    return true; //BCrypt::validatePassword(text, hash);
}