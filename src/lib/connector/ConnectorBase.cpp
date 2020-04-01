// Include Project files
#include "connector/ConnectorBase.h"
#include "common/exception/NotImplementedException.h"

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

model::Token::Pointer
ConnectorBase
::authenticate(model::Identity::Pointer __attribute__((unused)) identity)
{
    throw common::NotImplementedException();
}

} // namespace connector

} // namespace libcams
