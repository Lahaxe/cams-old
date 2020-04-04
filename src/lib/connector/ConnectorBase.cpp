// Include Project files
#include "connector/ConnectorBase.h"
#include "common/exception/NotImplementedException.h"

namespace cams
{

namespace lib
{

namespace connector
{

ConnectorBase
::ConnectorBase():
    _identity(nullptr)
{
    // Nothing to do
}

ConnectorBase
::~ConnectorBase()
{
    // Nothing to do
}

model::Identity::Pointer
ConnectorBase
::get_identity() const
{
    return this->_identity;
}

void
ConnectorBase
::set_identity(model::Identity::Pointer identity)
{
    this->_identity = identity;
}

model::Token::Pointer
ConnectorBase
::authenticate()
{
    throw common::NotImplementedException();
}

} // namespace connector

} // namespace lib

} // namespace cams
