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
    EntityBase(),
    _userid(Attribute<std::string>::New(TOKEN_USERID)),
    _username(Attribute<std::string>::New(TOKEN_USERNAME)),
    _token(Attribute<std::string>::New(TOKEN_TOKEN))
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
    return this->_userid->get_value();
}

void
Token
::set_userid(std::string const & userid)
{
    this->_userid->set_value(userid);
}

std::string
Token
::get_username() const
{
    return this->_username->get_value();
}

void
Token
::set_username(std::string const & username)
{
    this->_username->set_value(username);
}

std::string
Token
::get_token() const
{
    return this->_token->get_value();
}

void
Token
::set_token(std::string const & token)
{
    this->_token->set_value(token);
}

void
Token
::to_json(QJsonObject & json) const
{
    EntityBase::to_json(json);
    this->_userid->to_json(json);
    this->_username->to_json(json);
    this->_token->to_json(json);
}

void
Token
::from_json(QJsonObject const & json)
{
    EntityBase::from_json(json);
    this->_userid->from_json(json);
    this->_username->from_json(json);
    this->_token->from_json(json);
}

} // namespace model

} // namespace libcams
