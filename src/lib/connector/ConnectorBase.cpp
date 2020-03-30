// Include Project files
#include "connector/ConnectorBase.h"

namespace libcams
{

namespace connector
{

ConnectorBase
::ConnectorBase()
{
    // Nothing to do
}

ConnectorBase
::~ConnectorBase()
{
    // Nothing to do
}

std::string
ConnectorBase
::authenticate(std::string const & user, std::string const & password)
{
    throw std::exception();
}

} // namespace connector

} // namespace libcams
