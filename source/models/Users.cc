//
// Created by asman on 12-03-2023.
//

#include "Users.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::codingVeda;

const std::string Users::Cols::_id = "id";
const std::string Users::Cols::_uid = "uid";
const std::string Users::Cols::_name = "name";
const std::string Users::Cols::_email = "email";
const std::string Users::Cols::_phone = "phone";
const std::string Users::Cols::_password = "password";
const std::string Users::Cols::_isPaused = "isPaused";
const std::string Users::Cols::_isBlacklisted = "isBlacklisted";
const std::string Users::primaryKeyName = "id";
const bool Users::hasPrimaryKey = true;
const std::string Users::tableName = "users";

const std::vector<typename Users::MetaData> Users::metaData_={
{"id","int32_t","int(11)",4,1,1,1},
{"uid","std::string","varchar(100)",100,0,0,0},
{"name","std::string","varchar(50)",50,0,0,0},
{"email","std::string","varchar(50)",50,0,0,1},
{"phone","int32_t","int(15)",4,0,0,1},
{"password","std::string","varchar(100)",100,0,0,1},
{"isPaused","int8_t","tinyint(1)",1,0,0,1},
{"isBlacklisted","int8_t","tinyint(1)",1,0,0,1}
};
const std::string &Users::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Users::Users(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["uid"].isNull())
        {
            uid_=std::make_shared<std::string>(r["uid"].as<std::string>());
        }
        if(!r["name"].isNull())
        {
            name_=std::make_shared<std::string>(r["name"].as<std::string>());
        }
        if(!r["email"].isNull())
        {
            email_=std::make_shared<std::string>(r["email"].as<std::string>());
        }
        if(!r["phone"].isNull())
        {
            phone_=std::make_shared<int32_t>(r["phone"].as<int32_t>());
        }
        if(!r["password"].isNull())
        {
            password_=std::make_shared<std::string>(r["password"].as<std::string>());
        }
        if(!r["isPaused"].isNull())
        {
            ispaused_=std::make_shared<int8_t>(r["isPaused"].as<int8_t>());
        }
        if(!r["isBlacklisted"].isNull())
        {
            isblacklisted_=std::make_shared<int8_t>(r["isBlacklisted"].as<int8_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 8 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            uid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            name_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            email_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            phone_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            password_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 6;
        if(!r[index].isNull())
        {
            ispaused_=std::make_shared<int8_t>(r[index].as<int8_t>());
        }
        index = offset + 7;
        if(!r[index].isNull())
        {
            isblacklisted_=std::make_shared<int8_t>(r[index].as<int8_t>());
        }
    }

}

Users::Users(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 8)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            uid_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            email_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            phone_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[4]].asInt64());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            ispaused_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[6]].asInt64());
        }
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        dirtyFlag_[7] = true;
        if(!pJson[pMasqueradingVector[7]].isNull())
        {
            isblacklisted_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[7]].asInt64());
        }
    }
}

Users::Users(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("uid"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["uid"].isNull())
        {
            uid_=std::make_shared<std::string>(pJson["uid"].asString());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("email"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["email"].isNull())
        {
            email_=std::make_shared<std::string>(pJson["email"].asString());
        }
    }
    if(pJson.isMember("phone"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["phone"].isNull())
        {
            phone_=std::make_shared<int32_t>((int32_t)pJson["phone"].asInt64());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
    if(pJson.isMember("isPaused"))
    {
        dirtyFlag_[6]=true;
        if(!pJson["isPaused"].isNull())
        {
            ispaused_=std::make_shared<int8_t>((int8_t)pJson["isPaused"].asInt64());
        }
    }
    if(pJson.isMember("isBlacklisted"))
    {
        dirtyFlag_[7]=true;
        if(!pJson["isBlacklisted"].isNull())
        {
            isblacklisted_=std::make_shared<int8_t>((int8_t)pJson["isBlacklisted"].asInt64());
        }
    }
}

void Users::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 8)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            uid_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            email_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            phone_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[4]].asInt64());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            ispaused_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[6]].asInt64());
        }
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        dirtyFlag_[7] = true;
        if(!pJson[pMasqueradingVector[7]].isNull())
        {
            isblacklisted_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[7]].asInt64());
        }
    }
}

void Users::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("uid"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["uid"].isNull())
        {
            uid_=std::make_shared<std::string>(pJson["uid"].asString());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("email"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["email"].isNull())
        {
            email_=std::make_shared<std::string>(pJson["email"].asString());
        }
    }
    if(pJson.isMember("phone"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["phone"].isNull())
        {
            phone_=std::make_shared<int32_t>((int32_t)pJson["phone"].asInt64());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
    if(pJson.isMember("isPaused"))
    {
        dirtyFlag_[6] = true;
        if(!pJson["isPaused"].isNull())
        {
            ispaused_=std::make_shared<int8_t>((int8_t)pJson["isPaused"].asInt64());
        }
    }
    if(pJson.isMember("isBlacklisted"))
    {
        dirtyFlag_[7] = true;
        if(!pJson["isBlacklisted"].isNull())
        {
            isblacklisted_=std::make_shared<int8_t>((int8_t)pJson["isBlacklisted"].asInt64());
        }
    }
}

const int32_t &Users::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Users::getId() const noexcept
{
    return id_;
}
void Users::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Users::PrimaryKeyType & Users::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Users::getValueOfUid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(uid_)
        return *uid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Users::getUid() const noexcept
{
    return uid_;
}
void Users::setUid(const std::string &pUid) noexcept
{
    uid_ = std::make_shared<std::string>(pUid);
    dirtyFlag_[1] = true;
}
void Users::setUid(std::string &&pUid) noexcept
{
    uid_ = std::make_shared<std::string>(std::move(pUid));
    dirtyFlag_[1] = true;
}
void Users::setUidToNull() noexcept
{
    uid_.reset();
    dirtyFlag_[1] = true;
}

const std::string &Users::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(name_)
        return *name_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Users::getName() const noexcept
{
    return name_;
}
void Users::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[2] = true;
}
void Users::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[2] = true;
}
void Users::setNameToNull() noexcept
{
    name_.reset();
    dirtyFlag_[2] = true;
}

const std::string &Users::getValueOfEmail() const noexcept
{
    const static std::string defaultValue = std::string();
    if(email_)
        return *email_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Users::getEmail() const noexcept
{
    return email_;
}
void Users::setEmail(const std::string &pEmail) noexcept
{
    email_ = std::make_shared<std::string>(pEmail);
    dirtyFlag_[3] = true;
}
void Users::setEmail(std::string &&pEmail) noexcept
{
    email_ = std::make_shared<std::string>(std::move(pEmail));
    dirtyFlag_[3] = true;
}

const int32_t &Users::getValueOfPhone() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(phone_)
        return *phone_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Users::getPhone() const noexcept
{
    return phone_;
}
void Users::setPhone(const int32_t &pPhone) noexcept
{
    phone_ = std::make_shared<int32_t>(pPhone);
    dirtyFlag_[4] = true;
}

const std::string &Users::getValueOfPassword() const noexcept
{
    const static std::string defaultValue = std::string();
    if(password_)
        return *password_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Users::getPassword() const noexcept
{
    return password_;
}
void Users::setPassword(const std::string &pPassword) noexcept
{
    password_ = std::make_shared<std::string>(pPassword);
    dirtyFlag_[5] = true;
}
void Users::setPassword(std::string &&pPassword) noexcept
{
    password_ = std::make_shared<std::string>(std::move(pPassword));
    dirtyFlag_[5] = true;
}

const int8_t &Users::getValueOfIspaused() const noexcept
{
    const static int8_t defaultValue = int8_t();
    if(ispaused_)
        return *ispaused_;
    return defaultValue;
}
const std::shared_ptr<int8_t> &Users::getIspaused() const noexcept
{
    return ispaused_;
}
void Users::setIspaused(const int8_t &pIspaused) noexcept
{
    ispaused_ = std::make_shared<int8_t>(pIspaused);
    dirtyFlag_[6] = true;
}

const int8_t &Users::getValueOfIsblacklisted() const noexcept
{
    const static int8_t defaultValue = int8_t();
    if(isblacklisted_)
        return *isblacklisted_;
    return defaultValue;
}
const std::shared_ptr<int8_t> &Users::getIsblacklisted() const noexcept
{
    return isblacklisted_;
}
void Users::setIsblacklisted(const int8_t &pIsblacklisted) noexcept
{
    isblacklisted_ = std::make_shared<int8_t>(pIsblacklisted);
    dirtyFlag_[7] = true;
}

void Users::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &Users::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "uid",
        "name",
        "email",
        "phone",
        "password",
        "isPaused",
        "isBlacklisted"
    };
    return inCols;
}

void Users::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getUid())
        {
            binder << getValueOfUid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getEmail())
        {
            binder << getValueOfEmail();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getPhone())
        {
            binder << getValueOfPhone();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getIspaused())
        {
            binder << getValueOfIspaused();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[7])
    {
        if(getIsblacklisted())
        {
            binder << getValueOfIsblacklisted();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Users::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    if(dirtyFlag_[5])
    {
        ret.push_back(getColumnName(5));
    }
    if(dirtyFlag_[6])
    {
        ret.push_back(getColumnName(6));
    }
    if(dirtyFlag_[7])
    {
        ret.push_back(getColumnName(7));
    }
    return ret;
}

void Users::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getUid())
        {
            binder << getValueOfUid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getEmail())
        {
            binder << getValueOfEmail();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getPhone())
        {
            binder << getValueOfPhone();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getIspaused())
        {
            binder << getValueOfIspaused();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[7])
    {
        if(getIsblacklisted())
        {
            binder << getValueOfIsblacklisted();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Users::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getUid())
    {
        ret["uid"]=getValueOfUid();
    }
    else
    {
        ret["uid"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getEmail())
    {
        ret["email"]=getValueOfEmail();
    }
    else
    {
        ret["email"]=Json::Value();
    }
    if(getPhone())
    {
        ret["phone"]=getValueOfPhone();
    }
    else
    {
        ret["phone"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    if(getIspaused())
    {
        ret["isPaused"]=getValueOfIspaused();
    }
    else
    {
        ret["isPaused"]=Json::Value();
    }
    if(getIsblacklisted())
    {
        ret["isBlacklisted"]=getValueOfIsblacklisted();
    }
    else
    {
        ret["isBlacklisted"]=Json::Value();
    }
    return ret;
}

Json::Value Users::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 8)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getUid())
            {
                ret[pMasqueradingVector[1]]=getValueOfUid();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[2]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getEmail())
            {
                ret[pMasqueradingVector[3]]=getValueOfEmail();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getPhone())
            {
                ret[pMasqueradingVector[4]]=getValueOfPhone();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getPassword())
            {
                ret[pMasqueradingVector[5]]=getValueOfPassword();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[6].empty())
        {
            if(getIspaused())
            {
                ret[pMasqueradingVector[6]]=getValueOfIspaused();
            }
            else
            {
                ret[pMasqueradingVector[6]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[7].empty())
        {
            if(getIsblacklisted())
            {
                ret[pMasqueradingVector[7]]=getValueOfIsblacklisted();
            }
            else
            {
                ret[pMasqueradingVector[7]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getUid())
    {
        ret["uid"]=getValueOfUid();
    }
    else
    {
        ret["uid"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getEmail())
    {
        ret["email"]=getValueOfEmail();
    }
    else
    {
        ret["email"]=Json::Value();
    }
    if(getPhone())
    {
        ret["phone"]=getValueOfPhone();
    }
    else
    {
        ret["phone"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    if(getIspaused())
    {
        ret["isPaused"]=getValueOfIspaused();
    }
    else
    {
        ret["isPaused"]=Json::Value();
    }
    if(getIsblacklisted())
    {
        ret["isBlacklisted"]=getValueOfIsblacklisted();
    }
    else
    {
        ret["isBlacklisted"]=Json::Value();
    }
    return ret;
}

bool Users::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("uid"))
    {
        if(!validJsonOfField(1, "uid", pJson["uid"], err, true))
            return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(2, "name", pJson["name"], err, true))
            return false;
    }
    if(pJson.isMember("email"))
    {
        if(!validJsonOfField(3, "email", pJson["email"], err, true))
            return false;
    }
    else
    {
        err="The email column cannot be null";
        return false;
    }
    if(pJson.isMember("phone"))
    {
        if(!validJsonOfField(4, "phone", pJson["phone"], err, true))
            return false;
    }
    else
    {
        err="The phone column cannot be null";
        return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(5, "password", pJson["password"], err, true))
            return false;
    }
    else
    {
        err="The password column cannot be null";
        return false;
    }
    if(pJson.isMember("isPaused"))
    {
        if(!validJsonOfField(6, "isPaused", pJson["isPaused"], err, true))
            return false;
    }
    else
    {
        err="The isPaused column cannot be null";
        return false;
    }
    if(pJson.isMember("isBlacklisted"))
    {
        if(!validJsonOfField(7, "isBlacklisted", pJson["isBlacklisted"], err, true))
            return false;
    }
    else
    {
        err="The isBlacklisted column cannot be null";
        return false;
    }
    return true;
}
bool Users::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                               const std::vector<std::string> &pMasqueradingVector,
                                               std::string &err)
{
    if(pMasqueradingVector.size() != 8)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[3] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[5].empty())
      {
          if(pJson.isMember(pMasqueradingVector[5]))
          {
              if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[5] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[6].empty())
      {
          if(pJson.isMember(pMasqueradingVector[6]))
          {
              if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[6] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[7].empty())
      {
          if(pJson.isMember(pMasqueradingVector[7]))
          {
              if(!validJsonOfField(7, pMasqueradingVector[7], pJson[pMasqueradingVector[7]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[7] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Users::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("uid"))
    {
        if(!validJsonOfField(1, "uid", pJson["uid"], err, false))
            return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(2, "name", pJson["name"], err, false))
            return false;
    }
    if(pJson.isMember("email"))
    {
        if(!validJsonOfField(3, "email", pJson["email"], err, false))
            return false;
    }
    if(pJson.isMember("phone"))
    {
        if(!validJsonOfField(4, "phone", pJson["phone"], err, false))
            return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(5, "password", pJson["password"], err, false))
            return false;
    }
    if(pJson.isMember("isPaused"))
    {
        if(!validJsonOfField(6, "isPaused", pJson["isPaused"], err, false))
            return false;
    }
    if(pJson.isMember("isBlacklisted"))
    {
        if(!validJsonOfField(7, "isBlacklisted", pJson["isBlacklisted"], err, false))
            return false;
    }
    return true;
}
bool Users::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                             const std::vector<std::string> &pMasqueradingVector,
                                             std::string &err)
{
    if(pMasqueradingVector.size() != 8)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
      if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
      {
          if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
              return false;
      }
      if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
      {
          if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, false))
              return false;
      }
      if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
      {
          if(!validJsonOfField(7, pMasqueradingVector[7], pJson[pMasqueradingVector[7]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Users::validJsonOfField(size_t index,
                             const std::string &fieldName,
                             const Json::Value &pJson,
                             std::string &err,
                             bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 100)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 100)";
                return false;
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 50)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 50)";
                return false;
            }

            break;
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 50)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 50)";
                return false;
            }

            break;
        case 4:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 5:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 100)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 100)";
                return false;
            }

            break;
        case 6:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 7:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
    }
    return true;
}
