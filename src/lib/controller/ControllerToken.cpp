// Include Project files
#include "common/exception/RefusedLoginException.h"
#include "controller/ControllerToken.h"
#include "controller/MissingIdentityException.h"

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
    auto token = this->_connector->authenticate(this->_identity);

    if (token == nullptr)
    {
        throw common::RefusedLoginException();
    }

    // Create a JSON Response
    QJsonObject object;
    token->to_json(object);

    QJsonDocument document(object);
    return document;
}

}

}
