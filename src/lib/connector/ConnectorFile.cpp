// Include Standard library
#include <experimental/filesystem>
#include <iostream>

#include <boost/algorithm/string.hpp>

// Include Qt files
#include <QDateTime>
#include <QTimeZone>
#include <QUuid>

// Include Project files
#include "common/base64.h"
#include "common/configuration/Configuration.h"
#include "common/json/JsonTools.h"
#include "connector/ConnectorFile.h"
#include "model/users/User.h"
#include "model/users/Token.h"

namespace cams
{

namespace lib
{

namespace connector
{

ConnectorFile::Pointer
ConnectorFile
::New()
{
    return Pointer(new ConnectorFile());
}

ConnectorFile
::ConnectorFile():
    ConnectorBase()
{
    // Nothing to do
}

ConnectorFile
::~ConnectorFile()
{
    // Nothing to do
}

std::string
ConnectorFile
::class_name()
{
    return std::string("file");
}

model::Token::Pointer
ConnectorFile
::authenticate()
{
    auto root_path = common::Configuration::instance().get_connector_file_root_path();

    model::User::Pointer user = nullptr;
    // For each file in users directory
    for (auto& filename : std::experimental::filesystem::v1::directory_iterator(root_path + "/users"))
    {
        QJsonObject object;
        if (common::json::from_file(object, filename.path()))
        {
            user = model::User::New();
            user->from_json(object);

            if (user->get_name()->get_value() == this->get_identity()->get_login())
            {
                // find User => check password
                if (user->get_password()->get_value() != common::to_base64(this->get_identity()->get_password()))
                {
                    return nullptr;
                }
                break;
            }
            else
            {
                user = nullptr;
            }
        }
    }

    if (user == nullptr)
    {
        return nullptr;
    }

    // Create the token object
    auto token = model::Token::New();
    token->set_userid(user->get_id());
    token->set_username(user->get_name()->get_value());
    token->set_token(this->_generate_token(user->get_id()));

    return token;
}

std::vector<model::User::Pointer>
ConnectorFile
::get_users()
{
    if (!_is_good_token(this->get_identity()->get_token()))
    {
        // A revoir => BadTokenException
        throw std::exception();
    }

    auto root_path = common::Configuration::instance().get_connector_file_root_path();

    std::vector<model::User::Pointer> users;
    // For each file in users directory
    for (auto& filename : std::experimental::filesystem::v1::directory_iterator(root_path + "/users"))
    {
        QJsonObject object;
        if (common::json::from_file(object, filename.path()))
        {
            auto user = model::User::New();
            user->from_json(object);
            users.push_back(user);
        }
    }

    return users;
}

model::User::Pointer
ConnectorFile
::get_user_by_id(std::string const & id)
{
    if (!_is_good_token(this->get_identity()->get_token()))
    {
        // A revoir => BadTokenException
        throw std::exception();
    }

    std::stringstream filepath;
    filepath << common::Configuration::instance().get_connector_file_root_path()
             << "/users/" << id << ".json";
    if (!std::experimental::filesystem::v1::is_regular_file(std::experimental::filesystem::v1::path(filepath.str())))
    {
        return nullptr;
    }

    QJsonObject object;
    if (!common::json::from_file(object, filepath.str()))
    {
        // A revoir => CamsException ?
        throw std::exception();
    }

    auto user = model::User::New();
    user->from_json(object);
    return user;
}

void
ConnectorFile
::post_user(model::User::Pointer user)
{
    if (!_is_good_token(this->get_identity()->get_token()))
    {
        // A revoir => BadTokenException
        throw std::exception();
    }

    std::stringstream filepath;
    std::string uuid;
    do
    {
        uuid = QUuid::createUuid().toString().toStdString();
        boost::erase_all(uuid, "{");
        boost::erase_all(uuid, "}");

        filepath << common::Configuration::instance().get_connector_file_root_path()
                 << "/users/" << uuid << ".json";
    }
    while (std::experimental::filesystem::v1::is_regular_file(std::experimental::filesystem::v1::path(filepath.str())));

    user->set_id(uuid);

    QJsonObject json_user;
    user->to_json(json_user);

    if (!common::json::to_file(json_user, filepath.str()))
    {
        // A revoir
        throw std::exception();
    }
}

void
ConnectorFile
::put_user(model::User::Pointer user)
{
    if (!_is_good_token(this->get_identity()->get_token()))
    {
        // A revoir => BadTokenException
        throw std::exception();
    }

    QJsonObject json_user;
    user->to_json(json_user);

    std::stringstream filepath;
    filepath << common::Configuration::instance().get_connector_file_root_path()
             << "/users/" << user->get_id() << ".json";
    if (!common::json::to_file(json_user, filepath.str()))
    {
        // A revoir
        throw std::exception();
    }
}

void
ConnectorFile
::patch_user(model::User::Pointer user)
{
    if (!_is_good_token(this->get_identity()->get_token()))
    {
        // A revoir => BadTokenException
        throw std::exception();
    }

    auto current_user = this->get_user_by_id(user->get_id());
    if (current_user == nullptr)
    {
        // A revoir => 404
        throw std::exception();
    }

    current_user->patch_from_other(user);

    QJsonObject json_user;
    current_user->to_json(json_user);

    std::stringstream filepath;
    filepath << common::Configuration::instance().get_connector_file_root_path()
             << "/users/" << user->get_id() << ".json";
    if (!common::json::to_file(json_user, filepath.str()))
    {
        // A revoir
        throw std::exception();
    }
}

model::User::Pointer
ConnectorFile
::delete_user_by_id(std::string const & id)
{
    if (!_is_good_token(this->get_identity()->get_token()))
    {
        // A revoir => BadTokenException
        throw std::exception();
    }

    std::stringstream filepath;
    filepath << common::Configuration::instance().get_connector_file_root_path()
             << "/users/" << id << ".json";
    if (!std::experimental::filesystem::v1::is_regular_file(std::experimental::filesystem::v1::path(filepath.str())))
    {
        return nullptr;
    }

    QJsonObject object;
    if (!common::json::from_file(object, filepath.str()))
    {
        // A revoir => Log an error
    }

    if (!std::experimental::filesystem::v1::remove(std::experimental::filesystem::v1::path(filepath.str())))
    {
        // A revoir => Error
        throw std::exception();
    }

    auto user = model::User::New();
    user->from_json(object);
    return user;
}

void
ConnectorFile
::post_stamp(model::Stamp::Pointer stamp)
{
    if (!_is_good_token(this->get_identity()->get_token()))
    {
        // A revoir => BadTokenException
        throw std::exception();
    }

    std::stringstream filepath;
    std::string uuid;
    do
    {
        uuid = QUuid::createUuid().toString().toStdString();
        boost::erase_all(uuid, "{");
        boost::erase_all(uuid, "}");

        filepath << common::Configuration::instance().get_connector_file_root_path()
                 << "/stamps/" << uuid << ".json";
    }
    while (std::experimental::filesystem::v1::is_regular_file(std::experimental::filesystem::v1::path(filepath.str())));

    stamp->set_id(uuid);

    QJsonObject json_stamp;
    stamp->to_json(json_stamp);

    if (!common::json::to_file(json_stamp, filepath.str()))
    {
        // A revoir
        throw std::exception();
    }
}

std::string
ConnectorFile
::_generate_token(std::string const & userid) const
{
    auto now = QDateTime::currentDateTime();

    std::stringstream buffer;
    buffer << now.toString(QString("yyyy-MM-ddThh-mm-ss")).toStdString()
           << "|"
           << now.timeZone().displayName(QTimeZone::StandardTime, QTimeZone::OffsetName).toStdString()
           << "|" << userid;

    return common::to_base64(buffer.str());
}

bool
ConnectorFile
::_is_good_token(std::string const & token) const
{
    auto cleartoken = common::from_base64(token);

    std::vector<std::string> parts;
    boost::split(parts, cleartoken, boost::is_any_of("|"));

    // Should be in 3 parts
    if (parts.size() != 3)
    {
        return false;
    }

    // Check timestamp
    auto timestamp = QDateTime::fromString(QString(parts[0].c_str()), QString("yyyy-MM-ddThh-mm-ss"));
    auto now = QDateTime::currentDateTime();

    auto diff_hours = timestamp.secsTo(now) / 3600;
    if (diff_hours > 24) // Token available 24hours
    {
        return false;
    }

    // Check User
    std::stringstream filepath;
    filepath << common::Configuration::instance().get_connector_file_root_path()
             << "/users/" << parts[2] << ".json";

    if (!std::experimental::filesystem::v1::is_regular_file(std::experimental::filesystem::v1::path(filepath.str())))
    {
        return false;
    }

    return true;
}

} // namespace connector

} // namespace lib

} // namespace cams
