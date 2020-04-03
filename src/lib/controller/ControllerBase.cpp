// Include Standard library
#include <functional>
#include <map>
#include <vector>

// Include Boost library
#include <boost/algorithm/string.hpp>

// Include Project files
#include "controller/ControllerBase.h"
#include "controller/NotImplementedActionException.h"
#include "controller/UnknownActionException.h"

namespace cams
{

namespace lib
{

namespace controller
{

ControllerBase
::ControllerBase():
    _connector(nullptr)
{
    // Nothing to do
}

ControllerBase
::~ControllerBase()
{
    // Nothing to do
}

connector::ConnectorBase::Pointer
ControllerBase
::get_connector() const
{
    return this->_connector;
}

void
ControllerBase
::set_connector(connector::ConnectorBase::Pointer connector)
{
    this->_connector = connector;
}

bool
ControllerBase
::exists_action(std::string const & action) const
{
    auto action_uppercase = action;
    boost::to_upper(action_uppercase);

    bool action_exist = false;
    std::vector<std::string> actions = {
        ACTION_GET, ACTION_POST, ACTION_PUT,
        ACTION_PATCH, ACTION_DELETE, ACTION_OPTIONS
    };
    for (auto iter = actions.begin(); iter != actions.end(); ++iter)
    {
        if (*iter == action_uppercase)
        {
            // Find it
            action_exist = true;
            break;
        }
    }

    return action_exist;
}

QJsonDocument
ControllerBase
::execute(std::string const & action, std::string const & ressource, QJsonDocument const & document)
{
    auto action_uppercase = action;
    boost::to_upper(action_uppercase);

    typedef std::map<std::string, std::function<QJsonDocument (std::string const &, QJsonDocument const &)> > actions_list_type;

    actions_list_type actions = {
        { ACTION_GET, std::bind(&ControllerBase::execute_get, this, std::placeholders::_1, std::placeholders::_2) },
        { ACTION_POST, std::bind(&ControllerBase::execute_post, this, std::placeholders::_1, std::placeholders::_2) },
        { ACTION_PUT, std::bind(&ControllerBase::execute_put, this, std::placeholders::_1, std::placeholders::_2) },
        { ACTION_PATCH, std::bind(&ControllerBase::execute_patch, this, std::placeholders::_1, std::placeholders::_2) },
        { ACTION_DELETE, std::bind(&ControllerBase::execute_delete, this, std::placeholders::_1, std::placeholders::_2) },
        { ACTION_OPTIONS, std::bind(&ControllerBase::execute_options, this, std::placeholders::_1, std::placeholders::_2) }
    };

    if (actions.find(action_uppercase) == actions.end())
    {
        throw UnknownActionException(action);
    }

    return actions[action_uppercase](ressource, document);
}

QJsonDocument
ControllerBase
::execute_get(std::string const & ressource, QJsonDocument const & document)
{
    throw NotImplementedActionException(ACTION_GET);
}

QJsonDocument
ControllerBase
::execute_post(std::string const & ressource, QJsonDocument const & document)
{
    throw NotImplementedActionException(ACTION_POST);
}

QJsonDocument
ControllerBase
::execute_put(std::string const & ressource, QJsonDocument const & document)
{
    throw NotImplementedActionException(ACTION_PUT);
}

QJsonDocument
ControllerBase
::execute_patch(std::string const & ressource, QJsonDocument const & document)
{
    throw NotImplementedActionException(ACTION_PATCH);
}

QJsonDocument
ControllerBase
::execute_delete(std::string const & ressource, QJsonDocument const & document)
{
    throw NotImplementedActionException(ACTION_DELETE);
}

QJsonDocument
ControllerBase
::execute_options(std::string const & ressource, QJsonDocument const & document)
{
    throw NotImplementedActionException(ACTION_OPTIONS);
}

}

}

}
