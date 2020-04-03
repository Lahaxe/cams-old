// Include Boost files
#include <boost/algorithm/string.hpp>

// Include Project files
#include "arguments/Arguments.h"
#include "arguments/MissingArgumentException.h"
#include "arguments/UnknownArgumentException.h"

namespace cams
{

namespace cli
{

Arguments
::Arguments(int argc, char *argv[]):
    _display_help(false), _action(""), _controller(""),
    _user(""), _password(""), _token(""),
    _json_file(""), _json_string(""), _ressource_path("")
{
    this->_parse(argc, argv);
}

Arguments
::~Arguments()
{
    // Nohting to do
}

bool
Arguments
::get_display_help() const
{
    return this->_display_help;
}

void
Arguments
::set_display_help(bool display_help)
{
    this->_display_help = display_help;
}

std::string
Arguments
::get_action() const
{
    return this->_action;
}

void
Arguments
::set_action(std::string const & action)
{
    this->_action = action;
}

std::string
Arguments
::get_controller() const
{
    return this->_controller;
}

void
Arguments
::set_controller(std::string const & controller)
{
    this->_controller = controller;
}

std::string
Arguments
::get_user() const
{
    return this->_user;
}

void
Arguments
::set_user(std::string const & user)
{
    this->_user = user;
}

std::string
Arguments
::get_password() const
{
    return this->_password;
}

void
Arguments
::set_password(std::string const & password)
{
    this->_password = password;
}

std::string
Arguments
::get_token() const
{
    return this->_token;
}

void
Arguments
::set_token(std::string const & token)
{
    this->_token = token;
}

std::string
Arguments
::get_json_file() const
{
    return this->_json_file;
}

void
Arguments
::set_json_file(std::string const & json_file)
{
    this->_json_file = json_file;
}

std::string
Arguments
::get_json_string() const
{
    return this->_json_string;
}

void
Arguments
::set_json_string(std::string const & json_string)
{
    this->_json_string = json_string;
}

std::string
Arguments
::get_ressource_path() const
{
    return this->_ressource_path;
}

void
Arguments
::set_ressource_path(std::string const & ressource_path)
{
    this->_ressource_path = ressource_path;
}

void Arguments::_parse(int argc, char *argv[])
{
    for (int current_arg = 1; current_arg < argc; ++current_arg)
    {
        if (std::string(argv[current_arg]) == std::string("help") ||
            std::string(argv[current_arg]) == std::string("--help") ||
            std::string(argv[current_arg]) == std::string("-h"))
        {
            this->set_display_help(true);
            break;
        }
        else if (current_arg == 1)
        {
            this->set_action(std::string(argv[current_arg]));
        }
        else if (current_arg == 2)
        {
            auto controller_lowercase = std::string(argv[current_arg]);
            boost::to_lower(controller_lowercase);
            this->set_controller(controller_lowercase);
        }
        else if (std::string(argv[current_arg]) == std::string("--user") ||
            std::string(argv[current_arg]) == std::string("-u"))
        {
            if (argc < current_arg + 2)
            {
                throw MissingArgumentException("User");
            }

            ++current_arg;
            this->set_user(argv[current_arg]);
        }
        else if (std::string(argv[current_arg]) == std::string("--password") ||
            std::string(argv[current_arg]) == std::string("-p"))
        {
            if (argc < current_arg + 2)
            {
                throw MissingArgumentException("Password");
            }

            ++current_arg;
            this->set_password(argv[current_arg]);
        }
        else if (std::string(argv[current_arg]) == std::string("--token") ||
            std::string(argv[current_arg]) == std::string("-t"))
        {
            if (argc < current_arg + 2)
            {
                throw MissingArgumentException("Token");
            }

            ++current_arg;
            this->set_token(argv[current_arg]);
        }
        else if (std::string(argv[current_arg]) == std::string("--jsonfile") ||
            std::string(argv[current_arg]) == std::string("-f"))
        {
            if (argc < current_arg + 2)
            {
                throw MissingArgumentException("Jsonfile");
            }

            ++current_arg;
            this->set_json_file(argv[current_arg]);
        }
        else if (std::string(argv[current_arg]) == std::string("--json") ||
            std::string(argv[current_arg]) == std::string("-j"))
        {
            if (argc < current_arg + 2)
            {
                throw MissingArgumentException("Json");
            }

            ++current_arg;
            this->set_json_string(argv[current_arg]);
        }
        else if (std::string(argv[current_arg]) == std::string("--ressource") ||
            std::string(argv[current_arg]) == std::string("-r"))
        {
            if (argc < current_arg + 2)
            {
                throw MissingArgumentException("Ressource");
            }

            ++current_arg;
            this->set_ressource_path(argv[current_arg]);
        }
        else
        {
            throw UnknownArgumentException(std::string(argv[current_arg]));
        }
    }

    if (this->get_display_help() == true)
    {
        return;
    }

    if (this->get_action().empty())
    {
        throw MissingArgumentException("Action");
    }

    if (this->get_controller().empty())
    {
        throw MissingArgumentException("Controller");
    }
}

}

}
