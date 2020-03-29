// Include Standard library
#include <sstream>

// Include Project files
#include "controller/RefusedIdentityException.h"

namespace libcams
{

namespace controller
{

RefusedIdentityException
::RefusedIdentityException():
    common::CamsException("Login and/or password are invalid")
{
    // Nothing to do
}

RefusedIdentityException
::~RefusedIdentityException() noexcept
{
    // Nothing to do
}

} // namespace controller

} // namespace libcams
