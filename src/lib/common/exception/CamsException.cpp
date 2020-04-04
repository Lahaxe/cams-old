#include <sstream>

#include <QJsonDocument>
#include <QJsonObject>

// Include Project files
#include "common/exception/CamsException.h"

namespace cams
{

namespace lib
{

namespace common
{

CamsException
::CamsException(std::string const & message, unsigned int code):
    _message(message), _code(code)
{
    // Nothing to do
}

CamsException
::~CamsException() noexcept
{
    // Nothing to do
}

char const*
CamsException
::what() const noexcept
{
    return this->_message.c_str();
}

std::string
CamsException
::to_json() const noexcept
{
    std::stringstream errorcode;
    errorcode << this->_code;

    QJsonObject json;
    json["error"] = QString(this->_message.c_str());
    json["errorcode"] = QString(errorcode.str().c_str());

    QJsonDocument document(json);
    return document.toJson().toStdString();
}

} // namespace common

} // namespace lib

} // namespace cams
