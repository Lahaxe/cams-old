// Include Project files
#include "model/core/EntityBase.h"

namespace cams
{

namespace lib
{

namespace model
{

EntityBase
::EntityBase():
    _id(Attribute<std::string>::New(ENTITYBASE_ID))
{
    // Nothing to do
}

EntityBase
::EntityBase(std::string const & id):
    _id(Attribute<std::string>::New(ENTITYBASE_ID, id))
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
::from_json(QJsonObject const & json)
{
    this->_id->from_json(json);
}

void
EntityBase
::to_json(QJsonObject & json) const
{
    this->_id->to_json(json);
}

} // namespace model

}

} // namespace cams
