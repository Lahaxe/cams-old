// Include Standard library
#include <experimental/filesystem>
#include <iostream>

#include <QDateTime>
#include <QFile>
#include <QJsonDocument>
#include <QTimeZone>

#include <model/users/User.h>

// Include Project files
#include "common/json/JsonTools.h"
#include "connector/ConnectorFile.h"

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

std::string
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
                if (user->get_password() != password)
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
           << "|" << user->get_name();

    QByteArray bytearray;
    bytearray.append(QString(buffer.str().c_str()));

    return bytearray.toBase64().toStdString();
}

}

}
