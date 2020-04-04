#ifndef _c00c119a_1518_468c_8ecc_1ff945ae70cd
#define _c00c119a_1518_468c_8ecc_1ff945ae70cd

// Include Standard library files
#include <sstream>

// Include Project files
#include "model/core/Attribute.h"

namespace cams
{

namespace lib
{

namespace model
{

template<typename T>
typename Attribute<T>::Pointer
Attribute<T>
::New(std::string const & name)
{
    return Pointer(new Attribute<T>(name));
}

template<typename T>
typename Attribute<T>::Pointer
Attribute<T>
::New(std::string const & name, const T &value)
{
    return Pointer(new Attribute<T>(name, value));
}

template<typename T>
Attribute<T>
::Attribute(std::string const & name):
    _name(name), _value(T()), _is_set(false)
{
    // Nothing to do
}

template<typename T>
Attribute<T>
::Attribute(std::string const & name, const T &value):
    _name(name), _value(value), _is_set(true)
{
    // Nothing to do
}

template<typename T>
Attribute<T>
::~Attribute()
{
    // Nothing to do
}

template<typename T>
std::string
Attribute<T>
::get_name() const
{
    return this->_name;
}

template<typename T>
void
Attribute<T>
::set_name(std::string const & name)
{
    this->_name = name;
}

template<typename T>
T
Attribute<T>
::get_value() const
{
    return this->_value;
}

template<typename T>
void
Attribute<T>
::set_value(const T& value)
{
    this->_value = value;
    this->_is_set = true;
}

template<typename T>
bool
Attribute<T>
::is_set() const
{
    return this->_is_set;
}

template<typename T>
void
Attribute<T>
::from_json(QJsonObject const & json)
{
    if (json.contains(QString(this->_name.c_str())))
    {
        this->set_value(json[QString(this->_name.c_str())].toString().toStdString());
    }
}

template<typename T>
void
Attribute<T>
::to_json(QJsonObject & json) const
{
    if (this->_is_set)
    {
        std::stringstream buffer;
        buffer << this->_value;
        json[QString(this->_name.c_str())] = QString(buffer.str().c_str());
    }
}

template<typename T>
void
Attribute<T>
::patch_from_other(ConstPointer other)
{
    if (other->is_set())
    {
        this->set_value(other->get_value());
    }
}

} // namespace model

} // namespace lib

} // namespace cams

#endif // _c00c119a_1518_468c_8ecc_1ff945ae70cd
