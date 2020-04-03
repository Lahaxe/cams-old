// Include Project files
#include "model/users/User.h"

namespace libcams
{

namespace model
{

User::Pointer
User
::New()
{
    return Pointer(new User());
}

User
::User():
    EntityBase(), _name(Attribute<std::string>::New(USER_NAME)),
    _password(Attribute<std::string>::New(USER_PASSWORD))
{
    //Nothing to do
}

User
::~User()
{
    // Nothing to do
}

std::string
User
::get_name() const
{
    return this->_name->get_value();
}

void
User
::set_name(std::string const & name)
{
    this->_name->set_value(name);
}

std::string
User
::get_password() const
{
    return this->_password->get_value();
}

void
User
::set_password(std::string const & password)
{
    this->_password->set_value(password);
}

void
User
::to_json(QJsonObject & json) const
{
    EntityBase::to_json(json);
    this->_name->to_json(json);
    this->_password->to_json(json);
}

void
User
::from_json(QJsonObject const & json)
{
    EntityBase::from_json(json);
    this->_name->from_json(json);
    this->_password->from_json(json);
}

void
User
::patch_from_other(ConstPointer other)
{
// TODO
}

} // namespace model

} // namespace libcams
