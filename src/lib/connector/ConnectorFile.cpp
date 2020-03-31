// Include Standard library
#include <experimental/filesystem>
#include <iostream>

// Include Qt files
#include <QDateTime>
#include <QTimeZone>

// Include Project files
#include "common/base64.h"
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

QJsonDocument
ConnectorFile
::authenticate(std::string const & login, std::string const & password)
{
    model::User::Pointer user = nullptr;
    // For each file in users directory
    for (auto& filename : std::experimental::filesystem::v1::directory_iterator("data/users"))
    {
        QJsonObject object;
        if (common::json::from_file(object, filename.path()))
        {
            user = model::User::New();
            user->from_json(object);

            if (user->get_name() == login)
            {
                // find User => check password
                if (user->get_password() != common::to_base64(password))
                {
                    throw std::exception();
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
        throw std::exception();
    }

    auto now = QDateTime::currentDateTime();

    std::stringstream buffer;
    buffer << now.toString(QString("yyyy-MM-ddThh-mm-ss")).toStdString()
           << "|"
           << now.timeZone().displayName(QTimeZone::StandardTime, QTimeZone::OffsetName).toStdString()
           << "|" << user->get_id();

    // Create the token object
    auto token = model::Token::New();
    token->set_userid(user->get_id());
    token->set_username(user->get_name());
    token->set_token(common::to_base64(buffer.str()));

    // Create a JSON Response
    QJsonObject object;
    token->to_json(object);

    QJsonDocument document(object);
    return document;
}

}

}
