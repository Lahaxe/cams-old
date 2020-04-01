// Include Project files
#include "common/exception/NotImplementedException.h"

namespace libcams
{

namespace common
{

NotImplementedException
::NotImplementedException():
    CamsException("Function is not yet implemented", 501)
{
    // Nothing to do
}

NotImplementedException
::~NotImplementedException() noexcept
{
    // Nothing to do
}

} // namespace common

} // namespace libcams
