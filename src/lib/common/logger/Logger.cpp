//
#include <sstream>

//
#include <boost/date_time/posix_time/posix_time.hpp>

// Include Project files
#include "common/logger/Logger.h"

Logger* Logger::_instance = nullptr;

Logger&
Logger
::instance()
{
   if (Logger::_instance == nullptr)
   {
       Logger::_instance = new Logger();
   }

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

void Logger::debug(const std::string &message)
{
    this->write(message, "DEBUG");
}

void Logger::info(const std::string &message)
{
    this->write(message, "INFO");
}

void Logger::warning(const std::string &message)
{
    this->write(message, "WARN");
}

void Logger::error(const std::string &message)
{
    this->write(message, "ERROR");
}

void Logger::fatal(const std::string &message)
{
    this->write(message, "FATAL");
}

void Logger::write(const std::string &message, const std::string &level)
{
    auto datetime = boost::posix_time::to_iso_string(
                boost::posix_time::second_clock::local_time());

    std::stringstream stream;
    stream << datetime << " - " << level << " - " << message;

    std::cout << stream.str() << std::endl;
}
