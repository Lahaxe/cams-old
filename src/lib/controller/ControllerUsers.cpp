// Include Project files
#include "controller/ControllerUsers.h"

namespace libcams
{

namespace controller
{

ControllerUsers::Pointer
ControllerUsers
::New()
{
    return Pointer(new ControllerUsers());
}

ControllerUsers
::ControllerUsers():
    ControllerBase()
{
    // Nothing to do
}

ControllerUsers
::~ControllerUsers()
{
    // Nothing to do
}

std::string
ControllerUsers
::class_name()
{
    return std::string("users");
}

QJsonDocument
ControllerUsers
::execute_get()
{
    return QJsonDocument();
}

}

}
