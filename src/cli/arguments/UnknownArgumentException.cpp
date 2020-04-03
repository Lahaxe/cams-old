// Include Standard library
#include <sstream>

// Include Project files
#include "arguments/UnknownArgumentException.h"

namespace camscli
{

UnknownArgumentException
::UnknownArgumentException(std::string const & argument):
    libcams::common::CamsException()
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

} // namespace camscli
