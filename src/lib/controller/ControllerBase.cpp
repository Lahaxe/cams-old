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

namespace libcams
{

namespace controller
{

ControllerBase
::ControllerBase():
    _identity(nullptr), _connector(nullptr)
{
    // Nothing to do
}

ControllerBase
::~ControllerBase()
{
    // Nothing to do
}

Identity::Pointer
ControllerBase
::get_identity() const
{
    return this->_identity;
}

void
ControllerBase
::set_identity(Identity::Pointer identity)
{
    this->_identity = identity;
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
::execute(std::string const & action)
{
    auto action_uppercase = action;
    boost::to_upper(action_uppercase);

    typedef std::map<std::string, std::function<QJsonDocument (void)> > actions_list_type;

    actions_list_type actions = {
        { ACTION_GET, std::bind(&ControllerBase::execute_get, this) },
        { ACTION_POST, std::bind(&ControllerBase::execute_post, this) },
        { ACTION_PUT, std::bind(&ControllerBase::execute_put, this) },
        { ACTION_PATCH, std::bind(&ControllerBase::execute_patch, this) },
        { ACTION_DELETE, std::bind(&ControllerBase::execute_delete, this) },
        { ACTION_OPTIONS, std::bind(&ControllerBase::execute_options, this) }
    };

    if (actions.find(action_uppercase) == actions.end())
    {
        throw UnknownActionException(action);
    }

    return actions[action_uppercase]();
}

QJsonDocument
ControllerBase
::execute_get()
{
    throw NotImplementedActionException(ACTION_GET);
}

QJsonDocument
ControllerBase
::execute_post()
{
    throw NotImplementedActionException(ACTION_POST);
}

QJsonDocument
ControllerBase
::execute_put()
{
    throw NotImplementedActionException(ACTION_PUT);
}

QJsonDocument
ControllerBase
::execute_patch()
{
    throw NotImplementedActionException(ACTION_PATCH);
}

QJsonDocument
ControllerBase
::execute_delete()
{
    throw NotImplementedActionException(ACTION_DELETE);
}

QJsonDocument
ControllerBase
::execute_options()
{
    throw NotImplementedActionException(ACTION_OPTIONS);
}

}

}
