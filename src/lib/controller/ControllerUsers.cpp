
#include <boost/algorithm/string.hpp>

#include <QJsonArray>

// Include Project files
#include "controller/ControllerUsers.h"

namespace cams
{

namespace lib
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
::execute_get(std::string const & ressource, QJsonDocument const & __attribute__((unused)) document)
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

    // A revoir => Bad way
    throw std::exception();
}

QJsonDocument
ControllerUsers
::execute_post(std::string const & ressource, QJsonDocument const & document)
{
    // POST users
    if (ressource.empty())
    {
        if (document.isNull() || document.isEmpty())
        {
            // A revoir => erreur
            throw std::exception();
        }

        auto user = model::User::New();
        user->from_json(document.object());

        this->_connector->post_user(user);

        QJsonObject json_user;
        user->to_json(json_user);
        return QJsonDocument(json_user);
    }

    // A revoir => Bad way
    throw std::exception();
}

QJsonDocument
ControllerUsers
::execute_put(std::string const & ressource, QJsonDocument const & document)
{
    std::vector<std::string> parts;
    boost::split(parts, ressource, boost::is_any_of("/"));

    // PUT users/{id}
    if (parts.size() == 1 && !parts[0].empty())
    {
        if (document.isNull() || document.isEmpty())
        {
            // A revoir => erreur
            throw std::exception();
        }

        auto user = model::User::New();
        user->from_json(document.object());
        user->set_id(parts[0]);

        this->_connector->put_user(user);

        QJsonObject json_user;
        user->to_json(json_user);
        return QJsonDocument(json_user);
    }

    // A revoir => Bad way
    throw std::exception();
}

QJsonDocument
ControllerUsers
::execute_patch(std::string const & ressource, QJsonDocument const & document)
{
    std::vector<std::string> parts;
    boost::split(parts, ressource, boost::is_any_of("/"));

    // PATCH users/{id}
    if (parts.size() == 1 && !parts[0].empty())
    {
        if (document.isNull() || document.isEmpty())
        {
            // A revoir => erreur
            throw std::exception();
        }

        auto user = model::User::New();
        user->from_json(document.object());
        user->set_id(parts[0]);

        this->_connector->patch_user(user);

        QJsonObject json_user;
        user->to_json(json_user);
        return QJsonDocument(json_user);
    }

    // A revoir => Bad way
    throw std::exception();
}

QJsonDocument
ControllerUsers
::execute_delete(std::string const & ressource, QJsonDocument const & __attribute__((unused)) document)
{
    std::vector<std::string> parts;
    boost::split(parts, ressource, boost::is_any_of("/"));

    // DELETE users/{id}
    if (parts.size() == 1 && !parts[0].empty())
    {
        auto user = this->_connector->delete_user_by_id(parts[0]);

        if (user == nullptr)
        {
            return QJsonDocument();
        }

        QJsonObject object;
        user->to_json(object);

        return QJsonDocument(object);
    }

    // A revoir => RessourceNotFindException
    throw std::exception();
}

QJsonDocument
ControllerUsers
::execute_options(std::string const & ressource, QJsonDocument const & __attribute__((unused)) document)
{
    // OPTIONS users
    if (ressource.empty())
    {
        QJsonArray options;
        options.push_back(QJsonValue(QString(ACTION_GET.c_str())));
        options.push_back(QJsonValue(QString(ACTION_POST.c_str())));
        options.push_back(QJsonValue(QString(ACTION_OPTIONS.c_str())));
        return QJsonDocument(options);
    }

    std::vector<std::string> parts;
    boost::split(parts, ressource, boost::is_any_of("/"));

    // OPTIONS users/{id}
    if (parts.size() == 1)
    {
        QJsonArray options;
        options.push_back(QJsonValue(QString(ACTION_GET.c_str())));
        options.push_back(QJsonValue(QString(ACTION_PUT.c_str())));
        options.push_back(QJsonValue(QString(ACTION_PATCH.c_str())));
        options.push_back(QJsonValue(QString(ACTION_DELETE.c_str())));
        options.push_back(QJsonValue(QString(ACTION_OPTIONS.c_str())));
        return QJsonDocument(options);
    }

    // A revoir => RessourceNotFindException
    throw std::exception();
}

} // namespace controller

} // namespace lib

} // namespace cams
