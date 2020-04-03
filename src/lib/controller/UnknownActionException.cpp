// Include Standard library
#include <sstream>

// Include Project files
#include "controller/UnknownActionException.h"

namespace cams
{

namespace lib
{

namespace controller
{

UnknownActionException
::UnknownActionException(std::string const & action):
    common::CamsException("", 400)
{
    std::stringstream message;
    message << "Given action is unknown: " << action;
    this->_message = message.str();
}

UnknownActionException
::~UnknownActionException() noexcept
{
    // Nothing to do
}

} // namespace controller

}

} // namespace libcams
