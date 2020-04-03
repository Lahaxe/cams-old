#include "common/configuration/Configuration.h"
#include "common/configuration/INIFileParser.h"

namespace cams
{

namespace lib
{

namespace common
{

Configuration * Configuration::_instance = nullptr;

Configuration &
Configuration
::instance()
{
    if (Configuration::_instance == nullptr)
    {
        Configuration::_instance = new Configuration();
    }
    return *Configuration::_instance;
}

void
Configuration
::delete_instance()
{
    if (Configuration::_instance != nullptr)
    {
        delete Configuration::_instance;
        Configuration::_instance = nullptr;
    }
}

Configuration
::Configuration():
    _connector_type("file"), _logger_type("cout")
{
    this->_load_configuration_file();
}

Configuration
::~Configuration()
{
    // Nothing to do
}

std::string
Configuration
::get_connector_type() const
{
    return this->_connector_type;
}

void
Configuration
::set_connector_type(std::string const & connector_type)
{
    this->_connector_type = connector_type;
}

std::string
Configuration
::get_logger_type() const
{
    return this->_logger_type;
}

void
Configuration
::set_logger_type(std::string const & logger_type)
{
    this->_logger_type = logger_type;
}

std::string
Configuration
::get_connector_file_root_path() const
{
    return this->_connector_file_root_path;
}

void
Configuration
::set_connector_file_root_path(std::string const & connector_file_root_path)
{
    this->_connector_file_root_path = connector_file_root_path;
}

void
Configuration
::_load_configuration_file()
{
    auto iniparser = INIFileParser::New("./cams.conf");
    iniparser->read();

    // Genreal part
    this->set_connector_type(iniparser->get_value("general.connector_type"));

    // Logger part
    this->set_logger_type(iniparser->get_value("logger.logger_type"));

    // Connector part
    this->set_connector_file_root_path(iniparser->get_value("connector_file.root_path"));
}

}

}

}
