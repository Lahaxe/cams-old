// Include Project files
#include "model/core/Attribute.h"

namespace libcams
{

namespace model
{

template<>
void
Attribute<std::string>
::from_json(QJsonObject const & json)
{
    if (json.contains(QString(this->_name.c_str())))
    {
        this->set_value(json[QString(this->_name.c_str())].toString().toStdString());
    }
}

template<>
void
Attribute<std::string>
::to_json(QJsonObject & json) const
{
    if (this->_is_set)
    {
        json[QString(this->_name.c_str())] = QString(this->_value.c_str());
    }
}

} // namespace model

} // namespace libcams
