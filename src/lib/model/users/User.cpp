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
::User(std::string const & id, std::string const & name):
    EntityBase(id), _name(name)
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
    return this->_name;
}

void
User
::set_name(std::string const & name)
{
    this->_name = name;
}

void
User
::to_json(QJsonObject & json) const
{
    EntityBase::to_json(json);
    json["name"] = QString(this->get_name().c_str());
}

void
User
::from_json(QJsonObject const & json)
{
    EntityBase::from_json(json);
    this->set_name(json["name"].toString().toStdString());
}

} // namespace model

} // namespace libcams
