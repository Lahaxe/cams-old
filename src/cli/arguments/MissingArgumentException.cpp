// Include Standard library
#include <sstream>

// Include Project files
#include "arguments/MissingArgumentException.h"

namespace cams
{

namespace cli
{

MissingArgumentException
::MissingArgumentException(std::string const & argument):
    lib::common::CamsException()
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

}

}
