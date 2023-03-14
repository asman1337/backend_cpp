//
// Created by asman on 12-03-2023.
//

#pragma once

#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>

#ifdef __cpp_impl_coroutine

#include <drogon/orm/CoroMapper.h>

#endif

#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon {
    namespace orm {
        class DbClient;

        using DbClientPtr = std::shared_ptr<DbClient>;
    }
}
namespace drogon_model {
    namespace codingVeda {

        class Users {
        public:
            struct Cols {
                static const std::string _id;
                static const std::string _uid;
                static const std::string _name;
                static const std::string _email;
                static const std::string _phone;
                static const std::string _password;
                static const std::string _isPaused;
                static const std::string _isBlacklisted;
            };

            const static int primaryKeyNumber;
            const static std::string tableName;
            const static bool hasPrimaryKey;
            const static std::string primaryKeyName;
            using PrimaryKeyType = int32_t;

            const PrimaryKeyType &getPrimaryKey() const;

            /**
             * @brief constructor
             * @param r One row of records in the SQL query result.
             * @param indexOffset Set the offset to -1 to access all columns by column names,
             * otherwise access all columns by offsets.
             * @note If the SQL is not a style of 'select * from table_name ...' (select all
             * columns by an asterisk), please set the offset to -1.
             */
            explicit Users(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

            /**
             * @brief constructor
             * @param pJson The json object to construct a new instance.
             */
            explicit Users(const Json::Value &pJson) noexcept(false);

            /**
             * @brief constructor
             * @param pJson The json object to construct a new instance.
             * @param pMasqueradingVector The aliases of table columns.
             */
            Users(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

            Users() = default;

            void updateByJson(const Json::Value &pJson) noexcept(false);

            void updateByMasqueradedJson(const Json::Value &pJson,
                                         const std::vector<std::string> &pMasqueradingVector) noexcept(false);

            static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);

            static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                           const std::vector<std::string> &pMasqueradingVector,
                                                           std::string &err);

            static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);

            static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                                         const std::vector<std::string> &pMasqueradingVector,
                                                         std::string &err);

            static bool validJsonOfField(size_t index,
                                         const std::string &fieldName,
                                         const Json::Value &pJson,
                                         std::string &err,
                                         bool isForCreation);

            /**  For column id  */
            ///Get the value of the column id, returns the default value if the column is null
            const int32_t &getValueOfId() const noexcept;

            ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
            const std::shared_ptr<int32_t> &getId() const noexcept;

            ///Set the value of the column id
            void setId(const int32_t &pId) noexcept;

            /**  For column uid  */
            ///Get the value of the column uid, returns the default value if the column is null
            const std::string &getValueOfUid() const noexcept;

            ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
            const std::shared_ptr<std::string> &getUid() const noexcept;

            ///Set the value of the column uid
            void setUid(const std::string &pUid) noexcept;

            void setUid(std::string &&pUid) noexcept;

            void setUidToNull() noexcept;

            /**  For column name  */
            ///Get the value of the column name, returns the default value if the column is null
            const std::string &getValueOfName() const noexcept;

            ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
            const std::shared_ptr<std::string> &getName() const noexcept;

            ///Set the value of the column name
            void setName(const std::string &pName) noexcept;

            void setName(std::string &&pName) noexcept;

            void setNameToNull() noexcept;

            /**  For column email  */
            ///Get the value of the column email, returns the default value if the column is null
            const std::string &getValueOfEmail() const noexcept;

            ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
            const std::shared_ptr<std::string> &getEmail() const noexcept;

            ///Set the value of the column email
            void setEmail(const std::string &pEmail) noexcept;

            void setEmail(std::string &&pEmail) noexcept;

            /**  For column phone  */
            ///Get the value of the column phone, returns the default value if the column is null
            const int32_t &getValueOfPhone() const noexcept;

            ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
            const std::shared_ptr<int32_t> &getPhone() const noexcept;

            ///Set the value of the column phone
            void setPhone(const int32_t &pPhone) noexcept;

            /**  For column password  */
            ///Get the value of the column password, returns the default value if the column is null
            const std::string &getValueOfPassword() const noexcept;

            ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
            const std::shared_ptr<std::string> &getPassword() const noexcept;

            ///Set the value of the column password
            void setPassword(const std::string &pPassword) noexcept;

            void setPassword(std::string &&pPassword) noexcept;

            /**  For column isPaused  */
            ///Get the value of the column isPaused, returns the default value if the column is null
            const int8_t &getValueOfIspaused() const noexcept;

            ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
            const std::shared_ptr<int8_t> &getIspaused() const noexcept;

            ///Set the value of the column isPaused
            void setIspaused(const int8_t &pIspaused) noexcept;

            /**  For column isBlacklisted  */
            ///Get the value of the column isBlacklisted, returns the default value if the column is null
            const int8_t &getValueOfIsblacklisted() const noexcept;

            ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
            const std::shared_ptr<int8_t> &getIsblacklisted() const noexcept;

            ///Set the value of the column isBlacklisted
            void setIsblacklisted(const int8_t &pIsblacklisted) noexcept;


            static size_t getColumnNumber() noexcept { return 8; }

            static const std::string &getColumnName(size_t index) noexcept(false);

            Json::Value toJson() const;

            Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
            /// Relationship interfaces
        private:
            friend drogon::orm::Mapper<Users>;
#ifdef __cpp_impl_coroutine
            friend drogon::orm::CoroMapper<Users>;
#endif

            static const std::vector<std::string> &insertColumns() noexcept;

            void outputArgs(drogon::orm::internal::SqlBinder &binder) const;

            const std::vector<std::string> updateColumns() const;

            void updateArgs(drogon::orm::internal::SqlBinder &binder) const;

            ///For mysql or sqlite3
            void updateId(const uint64_t id);

            std::shared_ptr<int32_t> id_;
            std::shared_ptr<std::string> uid_;
            std::shared_ptr<std::string> name_;
            std::shared_ptr<std::string> email_;
            std::shared_ptr<int32_t> phone_;
            std::shared_ptr<std::string> password_;
            std::shared_ptr<int8_t> ispaused_;
            std::shared_ptr<int8_t> isblacklisted_;
            struct MetaData {
                const std::string colName_;
                const std::string colType_;
                const std::string colDatabaseType_;
                const ssize_t colLength_;
                const bool isAutoVal_;
                const bool isPrimaryKey_;
                const bool notNull_;
            };
            static const std::vector<MetaData> metaData_;
            bool dirtyFlag_[8] = {false};
        public:
            static const std::string &sqlForFindingByPrimaryKey() {
                static const std::string sql = "select * from " + tableName + " where id = ?";
                return sql;
            }

            static const std::string &sqlForDeletingByPrimaryKey() {
                static const std::string sql = "delete from " + tableName + " where id = ?";
                return sql;
            }

            std::string sqlForInserting(bool &needSelection) const {
                std::string sql = "insert into " + tableName + " (";
                size_t parametersCount = 0;
                needSelection = false;
                sql += "id,";
                ++parametersCount;
                if (dirtyFlag_[1]) {
                    sql += "uid,";
                    ++parametersCount;
                }
                if (dirtyFlag_[2]) {
                    sql += "name,";
                    ++parametersCount;
                }
                if (dirtyFlag_[3]) {
                    sql += "email,";
                    ++parametersCount;
                }
                if (dirtyFlag_[4]) {
                    sql += "phone,";
                    ++parametersCount;
                }
                if (dirtyFlag_[5]) {
                    sql += "password,";
                    ++parametersCount;
                }
                if (dirtyFlag_[6]) {
                    sql += "isPaused,";
                    ++parametersCount;
                }
                if (dirtyFlag_[7]) {
                    sql += "isBlacklisted,";
                    ++parametersCount;
                }
                needSelection = true;
                if (parametersCount > 0) {
                    sql[sql.length() - 1] = ')';
                    sql += " values (";
                } else
                    sql += ") values (";

                sql += "default,";
                if (dirtyFlag_[1]) {
                    sql.append("?,");

                }
                if (dirtyFlag_[2]) {
                    sql.append("?,");

                }
                if (dirtyFlag_[3]) {
                    sql.append("?,");

                }
                if (dirtyFlag_[4]) {
                    sql.append("?,");

                }
                if (dirtyFlag_[5]) {
                    sql.append("?,");

                }
                if (dirtyFlag_[6]) {
                    sql.append("?,");

                }
                if (dirtyFlag_[7]) {
                    sql.append("?,");

                }
                if (parametersCount > 0) {
                    sql.resize(sql.length() - 1);
                }
                sql.append(1, ')');
                LOG_TRACE << sql;
                return sql;
            }
        };
    } // namespace codingVeda
} // namespace drogon_model
