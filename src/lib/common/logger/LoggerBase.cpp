// Include Project files
#include "common/logger/LoggerBase.h"

namespace cams
{

namespace lib
{

namespace common
{

LoggerBase
::LoggerBase()
{
    // Nothing to do
}

LoggerBase
::~LoggerBase()
{
    // Nothing to do
}

void
LoggerBase
::debug(const std::string &message)
{
    this->write(message, "DEBUG");
}

void
LoggerBase
::info(const std::string &message)
{
    this->write(message, "INFO");
}

void
LoggerBase
::warning(const std::string &message)
{
    this->write(message, "WARN");
}

void
LoggerBase
::error(const std::string &message)
{
    this->write(message, "ERROR");
}

void
LoggerBase
::fatal(const std::string &message)
{
    this->write(message, "FATAL");
}

} // namespace common

} // namespace lib

} // namespace cams
