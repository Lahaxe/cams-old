
#include <boost/algorithm/string.hpp>

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
::execute_get(std::string const & ressource)
{
    // GET users
    if (ressource.empty())
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

    std::vector<std::string> parts;
    boost::split(parts, ressource, boost::is_any_of("/"));

    // GET users/{id}
    if (parts.size() == 1)
    {
        auto user = this->_connector->get_user_by_id(parts[0]);

        if (user == nullptr)
        {
            // A revoir => RessourceNotFindException
            throw std::exception();
        }

        QJsonObject object;
        user->to_json(object);

        return QJsonDocument(object);
    }

    // A revoir => RessourceNotFindException
    throw std::exception();
}

}

}
