// Include Standard library
#include <sstream>

// Include Project files
#include "arguments/MissingArgumentException.h"

namespace camscli
{

MissingArgumentException
::MissingArgumentException(std::string const & argument):
    libcams::common::CamsException()
{
    std::stringstream message;
    message << "At least one argument is missing: " << argument;
    this->_message = message.str();
}

MissingArgumentException
::~MissingArgumentException() noexcept
{
    // Nothing to do
}

} // namespace camscli
