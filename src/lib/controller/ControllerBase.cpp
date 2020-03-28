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
::ControllerBase()
{
    // Nothing to do
}

ControllerBase
::~ControllerBase()
{
    // Nothing to do
}

bool
ControllerBase
::exists_action(std::string const & action) const
{
    auto action_uppercase = action;
    boost::to_upper(action_uppercase);

    bool action_exist = false;
    std::vector<std::string> actions = { "GET", "POST", "PUT", "PATCH", "DELETE", "OPTIONS" };
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

void
ControllerBase
::execute(std::string const & action)
{
    auto action_uppercase = action;
    boost::to_upper(action_uppercase);

    typedef std::map<std::string, std::function<void (void)> > actions_list_type;

    actions_list_type actions = {
        { "GET", std::bind(&ControllerBase::execute_get, this) },
        { "POST", std::bind(&ControllerBase::execute_post, this) },
        { "PUT", std::bind(&ControllerBase::execute_put, this) },
        { "PATCH", std::bind(&ControllerBase::execute_patch, this) },
        { "DELETE", std::bind(&ControllerBase::execute_delete, this) },
        { "OPTIONS", std::bind(&ControllerBase::execute_options, this) }
    };

    if (actions.find(action_uppercase) == actions.end())
    {
        throw UnknownActionException(action);
    }

    actions[action_uppercase]();
}

void
ControllerBase
::execute_get()
{
    throw NotImplementedActionException("GET");
}

void
ControllerBase
::execute_post()
{
    throw NotImplementedActionException("POST");
}

void
ControllerBase
::execute_put()
{
    throw NotImplementedActionException("PUT");
}

void
ControllerBase
::execute_patch()
{
    throw NotImplementedActionException("PATCH");
}

void
ControllerBase
::execute_delete()
{
    throw NotImplementedActionException("DELETE");
}

void
ControllerBase
::execute_options()
{
    throw NotImplementedActionException("OPTIONS");
}

}

}
