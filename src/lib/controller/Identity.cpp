// Include Project files
#include "controller/Identity.h"

namespace libcams
{

namespace controller
{

Identity::Pointer
Identity
::New(std::string const & login,
      std::string const & password,
      std::string const & token)
{
    return Pointer(new Identity(login, password, token));
}

Identity
::Identity(std::string const & login,
           std::string const & password,
           std::string const & token):
    _login(login), _password(password), _token(token)
{
    // Nothing to do
}

Identity
::~Identity()
{
    // Nothing to do
}

std::string
Identity
::get_login() const
{
    return this->_login;
}

void
Identity
::set_login(std::string const & login)
{
    this->_login = login;
}

std::string
Identity
::get_password() const
{
    return this->_password;
}

void
Identity
::set_password(std::string const & password)
{
    this->_password = password;
}

std::string
Identity
::get_token() const
{
    return this->_token;
}

void
Identity
::set_token(std::string const & token)
{
    this->_token = token;
}

}

}
