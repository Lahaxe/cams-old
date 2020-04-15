// Include Project files
#include "controller/ControllerFactory.h"
#include "controller/ControllerStamps.h"
#include "controller/ControllerUsers.h"
#include "controller/ControllerToken.h"

namespace cams
{

namespace lib
{

namespace controller
{

ControllerFactory * ControllerFactory::_instance = nullptr;

ControllerFactory &
ControllerFactory
::instance()
{
    if (ControllerFactory::_instance == nullptr)
    {
        ControllerFactory::_instance = new ControllerFactory();
    }
    return *ControllerFactory::_instance;
}

void
ControllerFactory
::delete_instance()
{
    if (ControllerFactory::_instance != nullptr)
    {
        delete ControllerFactory::_instance;
        ControllerFactory::_instance = nullptr;
    }
}

ControllerFactory
::ControllerFactory():
    common::BaseFactory<ControllerBase>()
{
    this->register_<ControllerStamps>();
    this->register_<ControllerUsers>();
    this->register_<ControllerToken>();
}

ControllerFactory
::~ControllerFactory()
{
    // Nothing to do
}

} // namespace controller

} // namespace lib

} // namespace cams
