// Include Standard library
#include <sstream>

// Include Project files
#include "camscli/UnknownArgumentException.h"

namespace libcams
{

namespace camscli
{

UnknownArgumentException
::UnknownArgumentException(std::string const & argument):
    common::CamsException()
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

} // namespace libcams
