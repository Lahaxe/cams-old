// Include Project files
#include "model/users/User.h"

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
