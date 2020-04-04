// Include Standard library
#include <sstream>

// Include Project files
#include "arguments/UnknownArgumentException.h"

namespace cams
{

namespace cli
{

UnknownArgumentException
::UnknownArgumentException(std::string const & argument):
    lib::common::CamsException()
{
    std::stringstream message;
    message << "At least one argument is unknown: " << argument;
    this->_message = message.str();
}

UnknownArgumentException
::~UnknownArgumentException() noexcept
{
    // Nothing to do
}

} // namespace cli

} // namespace cams
