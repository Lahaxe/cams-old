#include <QJsonArray>

// Include Project files
#include "controller/ControllerUsers.h"

namespace libcams
{

namespace controller
{

ControllerUsers::Pointer
ControllerUsers
::New()
{
    return Pointer(new ControllerUsers());
}

ControllerUsers
::ControllerUsers():
    ControllerBase()
{
    // Nothing to do
}

ControllerUsers
::~ControllerUsers()
{
    // Nothing to do
}

std::string
ControllerUsers
::class_name()
{
    return std::string("users");
}

QJsonDocument
ControllerUsers
::execute_get()
{
    auto users = this->_connector->get_users();
    QJsonArray users_list;
    for (auto& user : users)
    {
        QJsonObject json_user;
        user->to_json(json_user);
        users_list.push_back(json_user);
    }

    return QJsonDocument(users_list);
}

}

}
