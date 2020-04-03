#ifndef _c00c119a_1518_468c_8ecc_1ff945ae70cd
#define _c00c119a_1518_468c_8ecc_1ff945ae70cd

#include "model/core/Attribute.h"

namespace libcams
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

} // namespace model

} // namespace libcams

#endif // _c00c119a_1518_468c_8ecc_1ff945ae70cd
