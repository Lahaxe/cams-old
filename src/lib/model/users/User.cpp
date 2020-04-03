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

Attribute<std::string>::Pointer
User
::get_name() const
{
    return this->_name;
}

void
User
::set_name(std::string const & name)
{
    this->_name->set_value(name);
}

Attribute<std::string>::Pointer
User
::get_password() const
{
    return this->_password;
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
    this->_name->patch_from_other(other->get_name());
    this->_password->patch_from_other(other->get_password());
}

} // namespace model

} // namespace libcams
