// Include Standard library
#include <experimental/filesystem>

#include <QFile>
#include <QJsonDocument>

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
    bool user_authenticate = false;
    // For each file in users directory
    for (auto& filename : std::experimental::filesystem::v1::directory_iterator("data/users"))
    {
        QJsonObject object;
        if (common::json::from_file(object, filename.path()))
        {
            auto user = model::User::New();
            user->from_json(object);

            if (user->get_name() == login)
            {
                // find User => check password
                if (user->get_password() != password)
                {
                    throw std::exception();
                }
                user_authenticate = true;
                break;
            }
        }
    }
    return "Token OK";
}

}

}
