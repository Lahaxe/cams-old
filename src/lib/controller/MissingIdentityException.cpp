// Include Standard library
#include <sstream>

// Include Project files
#include "controller/MissingIdentityException.h"

namespace cams
{

namespace lib
{

namespace controller
{

MissingIdentityException
::MissingIdentityException():
    common::CamsException("Login and/or password are missing")
{
    // Nothing to do
}

MissingIdentityException
::~MissingIdentityException() noexcept
{
    // Nothing to do
}

} // namespace controller

} // namespace lib

} // namespace cams
