// Include Standard library
#include <sstream>

// Include Project files
#include "controller/UnknownControllerException.h"

namespace libcams
{

namespace controller
{

UnknownControllerException
::UnknownControllerException(std::string const & controller):
    common::CamsException()
{
    std::stringstream message;
    message << "Given controller is unknown: " << controller;
    this->_message = message.str();
}

UnknownControllerException
::~UnknownControllerException() noexcept
{
    // Nothing to do
}

} // namespace controller

} // namespace libcams
