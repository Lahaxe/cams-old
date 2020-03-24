// Include Project files
#include "common/exception/CamsException.h"

namespace libcams
{

namespace common
{

CamsException
::CamsException(std::string const & message):
    _message(message)
{
    // Nothing to do
}

CamsException
::~CamsException() noexcept
{
    // Nothing to do
}

char const*
CamsException
::what() const noexcept
{
    return this->_message.c_str();
}

} // namespace common

} // namespace libcams
