// Include Project files
#include "controller/ControllerToken.h"
#include "controller/MissingIdentityException.h"
#include "controller/RefusedIdentityException.h"

namespace libcams
{

namespace controller
{

ControllerToken::Pointer
ControllerToken
::New()
{
    return Pointer(new ControllerToken());
}

ControllerToken
::ControllerToken():
    ControllerBase()
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

QJsonDocument
ControllerToken
::execute_post()
{
    if (this->_identity->get_login() == "" || this->_identity->get_password() == "")
    {
        throw MissingIdentityException();
    }

    // Test l'authentification
    return this->_connector->authenticate(this->_identity->get_login(), this->_identity->get_password());
}

}

}
