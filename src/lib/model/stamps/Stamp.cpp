// Include Project files
#include "model/stamps/Stamp.h"

namespace cams
{

namespace lib
{

namespace model
{

Stamp::Pointer
Stamp
::New()
{
    return Pointer(new Stamp());
}

Stamp
::Stamp():
    EntityBase(),
    _country(Attribute<std::string>::New(STAMP_COUNTRY)),
    _year(Attribute<int>::New(STAMP_YEAR)),
    _value(Attribute<double>::New(STAMP_VALUE)),
    _currency(Attribute<std::string>::New(STAMP_CURRENCY))
{
    //Nothing to do
}

Stamp
::~Stamp()
{
    // Nothing to do
}

Attribute<std::string>::Pointer
Stamp
::get_country() const
{
    return this->_country;
}

void
Stamp
::set_country(std::string const & country)
{
    this->_country->set_value(country);
}

Attribute<int>::Pointer
Stamp
::get_year() const
{
    return this->_year;
}

void
Stamp
::set_year(int year)
{
    this->_year->set_value(year);
}

Attribute<double>::Pointer
Stamp
::get_value() const
{
    return this->_value;
}

void
Stamp
::set_value(double value)
{
    this->_value->set_value(value);
}

Attribute<std::string>::Pointer
Stamp
::get_currency() const
{
    return this->_currency;
}

void
Stamp
::set_currency(std::string const & currency)
{
    this->_currency->set_value(currency);
}

void
Stamp
::to_json(QJsonObject & json) const
{
    EntityBase::to_json(json);
    this->_country->to_json(json);
    this->_year->to_json(json);
    this->_value->to_json(json);
    this->_currency->to_json(json);
}

void
Stamp
::from_json(QJsonObject const & json)
{
    EntityBase::from_json(json);
    this->_country->from_json(json);
    this->_year->from_json(json);
    this->_value->from_json(json);
    this->_currency->from_json(json);
}

void
Stamp
::patch_from_other(ConstPointer other)
{
    this->_country->patch_from_other(other->get_country());
    this->_year->patch_from_other(other->get_year());
    this->_value->patch_from_other(other->get_value());
    this->_currency->patch_from_other(other->get_currency());
}

} // namespace model

} // namespace lib

} // namespace cams
