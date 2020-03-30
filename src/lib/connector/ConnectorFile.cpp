// Include Standard library
#include <experimental/filesystem>

#include <QFile>
#include <QJsonDocument>

#include <model/users/User.h>

// Include Project files
#include "connector/ConnectorFile.h"

namespace libcams
{

namespace connector
{

ConnectorFile::Pointer
ConnectorFile
::New()
{
    return Pointer(new ConnectorFile());
}

ConnectorFile
::ConnectorFile():
    ConnectorBase()
{
    // Nothing to do
}

ConnectorFile
::~ConnectorFile()
{
    // Nothing to do
}

std::string
ConnectorFile
::class_name()
{
    return std::string("file");
}

std::string
ConnectorFile
::authenticate(std::string const & login, std::string const & password)
{
    return "Token OK";
}

}

}
