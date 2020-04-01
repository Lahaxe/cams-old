// Include Project files
#include "common/exception/RefusedLoginException.h"

namespace libcams
{

namespace common
{

RefusedLoginException
::RefusedLoginException():
    common::CamsException("Login and/or password are invalid", 401)
{
    // Nothing to do
}

RefusedLoginException
::~RefusedLoginException() noexcept
{
    // Nothing to do
}

} // namespace common

} // namespace libcams
