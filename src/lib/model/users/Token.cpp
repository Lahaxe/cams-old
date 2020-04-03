// Include Project files
#include "model/users/Token.h"

namespace libcams
{

namespace model
{

Token::Pointer
Token
::New()
{
    return Pointer(new Token());
}

Token
::Token():
    EntityBase(), _userid(""), _username(""), _token("")
{
    //Nothing to do
}

Token
::~Token()
{
    // Nothing to do
}

std::string
Token
::get_userid() const
{
    return this->_userid;
}

void
Token
::set_userid(std::string const & userid)
{
    this->_userid = userid;
}

std::string
Token
::get_username() const
{
    return this->_username;
}

void
Token
::set_username(std::string const & username)
{
    this->_username = username;
}

std::string
Token
::get_token() const
{
    return this->_token;
}

void
Token
::set_token(std::string const & token)
{
    this->_token = token;
}

void
Token
::to_json(QJsonObject & json) const
{
    EntityBase::to_json(json);
    json["userid"] = QString(this->get_userid().c_str());
    json["username"] = QString(this->get_username().c_str());
    json["token"] = QString(this->get_token().c_str());
}

void
Token
::from_json(QJsonObject const & json)
{
    EntityBase::from_json(json);
    this->set_userid(json["userid"].toString().toStdString());
    this->set_username(json["username"].toString().toStdString());
    this->set_token(json["token"].toString().toStdString());
}

} // namespace model

} // namespace libcams
