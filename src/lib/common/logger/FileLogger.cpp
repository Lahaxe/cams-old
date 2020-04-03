// Include standard files
#include <sstream>

// Include boost files
#include <boost/date_time/posix_time/posix_time.hpp>

#include <QFile>

// Include Project files
#include "common/logger/FileLogger.h"

namespace cams
{

namespace lib
{

namespace common
{

FileLogger::Pointer
FileLogger
::New()
{
    return Pointer(new FileLogger());
}

FileLogger
::FileLogger():
    LoggerBase()
{
    // Nothing to do
}

FileLogger
::~FileLogger()
{
    // Nothing to do
}

std::string
FileLogger
::class_name()
{
    return std::string("file");
}

void
FileLogger
::write(const std::string &message, const std::string &level)
{
    auto datetime = boost::posix_time::to_iso_string(
                boost::posix_time::second_clock::local_time());

    std::stringstream stream;
    stream << datetime << " - " << level << " - " << message << "\r\n";

    QFile logfile("camscpp.log");
    logfile.open(QIODevice::WriteOnly | QIODevice::Append);
    logfile.write(stream.str().c_str());
    logfile.close();
}

}

}

}
