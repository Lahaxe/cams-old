// Include Project files
#include "controller/ControllerToken.h"

namespace libcams
{

namespace controller
{

ControllerToken::Pointer
ControllerToken
::New(Identity::Pointer identity)
{
    return Pointer(new ControllerToken(identity));
}

ControllerToken
::ControllerToken(Identity::Pointer identity):
    ControllerBase(identity)
{
    // Nothing to do
}

ControllerToken
::~ControllerToken()
{
    // Nothing to do
}

std::string
ControllerToken
::class_name()
{
    return std::string("token");
}

void
ControllerToken
::execute_post()
{
    // to be implemented
}

}

}
