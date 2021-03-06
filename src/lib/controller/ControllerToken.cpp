// Include Project files
#include "common/exception/RefusedLoginException.h"
#include "controller/ControllerToken.h"
#include "controller/MissingIdentityException.h"

namespace cams
{

namespace lib
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
::execute_post(std::string const & __attribute__((unused)) ressource,
               QJsonDocument const & __attribute__((unused)) document)
{
    // Test l'authentification
    auto token = this->_connector->authenticate();

    if (token == nullptr)
    {
        throw common::RefusedLoginException();
    }

    // Create a JSON Response
    QJsonObject object;
    token->to_json(object);
    return QJsonDocument(object);
}

} // namespace controller

} // namespace lib

} // namespace cams
