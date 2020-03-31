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

QJsonDocument
ConnectorBase
::authenticate(model::Identity::Pointer identity)
{
    throw std::exception();
}

} // namespace connector

} // namespace libcams
