// Include Project files
#include "model/core/EntityBase.h"

namespace libcams
{

namespace model
{

EntityBase
::EntityBase():
    _id(Attribute<std::string>::New())
{
    // Nothing to do
}

EntityBase
::EntityBase(std::string const & id):
    _id(Attribute<std::string>::New(id))
{
    // Nothing to do
}

EntityBase
::~EntityBase()
{
    // Nothing to do
}

std::string
EntityBase
::get_id() const
{
    return this->_id->get_value();
}

void
EntityBase
::set_id(std::string const & id)
{
    this->_id->set_value(id);
}

void
EntityBase
::to_json(QJsonObject & json) const
{
    if (this->_id->is_set())
    {
        json["id"] = QString(this->get_id().c_str());
    }
}

void
EntityBase
::from_json(QJsonObject const & json)
{
    if (json.contains(QString("id")))
    {
        this->set_id(json["id"].toString().toStdString());
    }
}

} // namespace model

} // namespace libcams
