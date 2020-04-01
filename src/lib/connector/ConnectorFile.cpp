// Include Standard library
#include <experimental/filesystem>
#include <iostream>

#include <boost/algorithm/string.hpp>

// Include Qt files
#include <QDateTime>
#include <QTimeZone>

// Include Project files
#include "common/base64.h"
#include "common/configuration/Configuration.h"
#include "common/json/JsonTools.h"
#include "connector/ConnectorFile.h"
#include "model/users/User.h"
#include "model/users/Token.h"

namespace libcams
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
    auto root_path = libcams::common::Configuration::instance().get_connector_file_root_path();

    model::User::Pointer user = nullptr;
    // For each file in users directory
    for (auto& filename : std::experimental::filesystem::v1::directory_iterator(root_path + "/users"))
    {
        QJsonObject object;
        if (common::json::from_file(object, filename.path()))
        {
            user = model::User::New();
            user->from_json(object);

            if (user->get_name() == this->get_identity()->get_login())
            {
                // find User => check password
                if (user->get_password() != common::to_base64(this->get_identity()->get_password()))
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
    token->set_username(user->get_name());
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

    auto root_path = libcams::common::Configuration::instance().get_connector_file_root_path();

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
    filepath << libcams::common::Configuration::instance().get_connector_file_root_path()
             << "/users/" << parts[2] << ".json";

    if (!std::experimental::filesystem::v1::is_regular_file(std::experimental::filesystem::v1::path(filepath.str())))
    {
        return false;
    }

    return true;
}

}

}
