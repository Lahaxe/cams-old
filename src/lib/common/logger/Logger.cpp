// Include Project files
#include "common/logger/Logger.h"

namespace libcams
{

namespace common
{

Logger* Logger::_instance = nullptr;

Logger&
Logger
::instance()
{
    return *Logger::_instance;
}

void
Logger
::delete_instance()
{
    if (Logger::_instance != nullptr)
    {
        delete Logger::_instance;
        Logger::_instance = nullptr;
    }
}

Logger
::Logger()
{
    // Nothing to do
}

Logger
::~Logger()
{
    // Nothing to do
}

void
Logger
::debug(const std::string &message)
{
    this->write(message, "DEBUG");
}

void
Logger
::info(const std::string &message)
{
    this->write(message, "INFO");
}

void
Logger
::warning(const std::string &message)
{
    this->write(message, "WARN");
}

void
Logger
::error(const std::string &message)
{
    this->write(message, "ERROR");
}

void
Logger
::fatal(const std::string &message)
{
    this->write(message, "FATAL");
}

} // namespace common

} // namespace libcams
