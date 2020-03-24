// Include Project files
#include "model/core/EntityBase.h"

namespace libcams
{

namespace model
{

EntityBase
::EntityBase(std::string const & id):
    _id(id)
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
    return this->_id;
}

void
EntityBase
::set_id(std::string const & id)
{
    this->_id = id;
}

} // namespace model

} // namespace libcams
