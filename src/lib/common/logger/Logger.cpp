// Include Project files
#include "common/logger/Logger.h"

namespace cams
{

namespace lib
{

namespace common
{

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
::Logger():
    _logger_writer(nullptr)
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
    if (this->_logger_writer != nullptr)
    {
        this->_logger_writer->debug(message);
    }
}

void
Logger
::info(const std::string &message)
{
    if (this->_logger_writer != nullptr)
    {
        this->_logger_writer->info(message);
    }
}

void
Logger
::warning(const std::string &message)
{
    if (this->_logger_writer != nullptr)
    {
        this->_logger_writer->warning(message);
    }
}

void
Logger
::error(const std::string &message)
{
    if (this->_logger_writer != nullptr)
    {
        this->_logger_writer->error(message);
    }
}

void
Logger
::fatal(const std::string &message)
{
    if (this->_logger_writer != nullptr)
    {
        this->_logger_writer->fatal(message);
    }
}

void
Logger
::set_logger_writer(LoggerBase::Pointer logger_writer)
{
    this->_logger_writer = logger_writer;
}

} // namespace common

} // namespace lib

} // namespace cams
