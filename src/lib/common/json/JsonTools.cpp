#include <QFile>
#include <QJsonDocument>

// Include Project files
#include "common/json/JsonTools.h"

namespace cams
{

namespace lib
{

namespace common
{

namespace json
{

bool
to_file(QJsonObject const & json, std::string const & filename)
{
    QFile file(QString(filename.c_str()));

    if (!file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QJsonDocument document(json);
    if (file.write(document.toJson()) == -1)
    {
        file.close();
        return false;
    }

    file.close();
    return true;
}

bool
from_file(QJsonObject & json, std::string const & filename)
{
    QFile file(QString(filename.c_str()));

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    auto data = file.readAll();
    file.close();

    auto document = QJsonDocument::fromJson(data);
    json = document.object();

    return true;
}

} // namespace json

} // namespace common

} // namespace lib

} // namespace cams
