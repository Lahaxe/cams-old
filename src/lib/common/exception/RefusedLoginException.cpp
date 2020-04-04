// Include Project files
#include "common/exception/RefusedLoginException.h"

namespace cams
{

namespace lib
{

namespace common
{

RefusedLoginException
::RefusedLoginException():
    CamsException("Login and/or password are invalid", 401)
{
    // Nothing to do
}

RefusedLoginException
::~RefusedLoginException() noexcept
{
    // Nothing to do
}

} // namespace common

} // namespace lib

} // namespace cams
