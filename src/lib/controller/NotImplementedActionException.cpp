
// Include Standard library
#include <sstream>

// Include Project files
#include "controller/NotImplementedActionException.h"

namespace libcams
{

namespace controller
{

NotImplementedActionException
::NotImplementedActionException(std::string const & action):
    common::CamsException()
{
    std::stringstream message;
    message << "The controller does not implement the action '" << action << "'";
    this->_message = message.str();
}

NotImplementedActionException
::~NotImplementedActionException() noexcept
{
    // Nothing to do
}

} // namespace controller

} // namespace libcams
