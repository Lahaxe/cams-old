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
::New()
{
    return Pointer(new Attribute<T>());
}

template<typename T>
typename Attribute<T>::Pointer
Attribute<T>
::New(const T &value)
{
    return Pointer(new Attribute<T>(value));
}

template<typename T>
Attribute<T>
::Attribute():
    _value(T()), _is_set(false)
{
    // Nothing to do
}

template<typename T>
Attribute<T>
::Attribute(const T &value):
    _value(value), _is_set(true)
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
