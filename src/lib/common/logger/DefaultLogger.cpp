// Include standard files
#include <sstream>

// Include boost files
#include <boost/date_time/posix_time/posix_time.hpp>

// Include Project files
#include "common/logger/DefaultLogger.h"

namespace cams
{

namespace lib
{

namespace common
{

DefaultLogger::Pointer
DefaultLogger
::New()
{
    return Pointer(new DefaultLogger());
}

DefaultLogger
::DefaultLogger():
    LoggerBase()
{
    // Nothing to do
}

DefaultLogger
::~DefaultLogger()
{
    // Nothing to do
}

std::string
DefaultLogger
::class_name()
{
    return std::string("cout");
}

void
DefaultLogger
::write(const std::string &message, const std::string &level)
{
    auto datetime = boost::posix_time::to_iso_string(
                boost::posix_time::second_clock::local_time());

    std::stringstream stream;
    stream << datetime << " - " << level << " - " << message;

    std::cout << stream.str() << std::endl;
}

}

}

}
