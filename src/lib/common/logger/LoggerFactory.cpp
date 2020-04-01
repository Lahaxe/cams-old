// Include Project files
#include "common/logger/LoggerFactory.h"
#include "common/logger/DefaultLogger.h"
#include "common/logger/FileLogger.h"

namespace libcams
{

namespace common
{

LoggerFactory * LoggerFactory::_instance = nullptr;

LoggerFactory &
LoggerFactory
::instance()
{
    if (LoggerFactory::_instance == nullptr)
    {
        LoggerFactory::_instance = new LoggerFactory();
    }
    return *LoggerFactory::_instance;
}

void
LoggerFactory
::delete_instance()
{
    if (LoggerFactory::_instance != nullptr)
    {
        delete LoggerFactory::_instance;
        LoggerFactory::_instance = nullptr;
    }
}

LoggerFactory
::LoggerFactory():
    common::BaseFactory<LoggerBase>()
{
    this->register_<DefaultLogger>();
    this->register_<FileLogger>();
}

LoggerFactory
::~LoggerFactory()
{
    // Nothing to do
}

} // namespace common

} // namespace libcams
