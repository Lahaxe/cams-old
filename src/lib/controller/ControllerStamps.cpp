
#include <boost/algorithm/string.hpp>

#include <QJsonArray>

// Include Project files
#include "controller/ControllerStamps.h"
#include "model/stamps/Stamp.h"

namespace cams
{

namespace lib
{

namespace controller
{

ControllerStamps::Pointer
ControllerStamps
::New()
{
    return Pointer(new ControllerStamps());
}

ControllerStamps
::ControllerStamps():
    ControllerBase()
{
    // Nothing to do
}

ControllerStamps
::~ControllerStamps()
{
    // Nothing to do
}

std::string
ControllerStamps
::class_name()
{
    return std::string("stamps");
}

QJsonDocument
ControllerStamps
::execute_get(std::string const & ressource, QJsonDocument const & __attribute__((unused)) document)
{
    // A revoir => Bad way
    throw std::exception();
}

QJsonDocument
ControllerStamps
::execute_post(std::string const & ressource, QJsonDocument const & document)
{
    // POST users
    if (ressource.empty())
    {
        if (document.isNull() || document.isEmpty())
        {
            // A revoir => erreur
            throw std::exception();
        }

        auto stamp = model::Stamp::New();
        stamp->from_json(document.object());

        this->_connector->post_stamp(stamp);

        QJsonObject json_stamp;
        stamp->to_json(json_stamp);
        return QJsonDocument(json_stamp);
    }

    // A revoir => Bad way
    throw std::exception();
}

QJsonDocument
ControllerStamps
::execute_options(std::string const & ressource, QJsonDocument const & __attribute__((unused)) document)
{
    // OPTIONS users
    if (ressource.empty())
    {
        QJsonArray options;
        options.push_back(QJsonValue(QString(ACTION_POST.c_str())));
        options.push_back(QJsonValue(QString(ACTION_OPTIONS.c_str())));
        return QJsonDocument(options);
    }

    // A revoir => RessourceNotFindException
    throw std::exception();
}

} // namespace controller

} // namespace lib

} // namespace cams
