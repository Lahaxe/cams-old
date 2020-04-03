// Include Project files
#include "connector/ConnectorFactory.h"
#include "connector/ConnectorFile.h"

namespace cams
{

namespace lib
{

namespace connector
{

ConnectorFactory * ConnectorFactory::_instance = nullptr;

ConnectorFactory &
ConnectorFactory
::instance()
{
    if (ConnectorFactory::_instance == nullptr)
    {
        ConnectorFactory::_instance = new ConnectorFactory();
    }
    return *ConnectorFactory::_instance;
}

void
ConnectorFactory
::delete_instance()
{
    if (ConnectorFactory::_instance != nullptr)
    {
        delete ConnectorFactory::_instance;
        ConnectorFactory::_instance = nullptr;
    }
}

ConnectorFactory
::ConnectorFactory():
    common::BaseFactory<ConnectorBase>()
{
    this->register_<ConnectorFile>();
}

ConnectorFactory
::~ConnectorFactory()
{
    // Nothing to do
}

}

}

}
