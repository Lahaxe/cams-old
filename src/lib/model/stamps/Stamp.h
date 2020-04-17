#ifndef _db4c988b_87fe_48a5_bf41_7ce5c8c04b79
#define _db4c988b_87fe_48a5_bf41_7ce5c8c04b79

// Include Project files
#include "model/core/EntityBase.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Data Model
namespace model
{

/// @brief Name of the User attribute 'Name'
const std::string STAMP_COUNTRY = "country";

/// @brief Name of the User attribute 'Password'
const std::string STAMP_YEAR = "year";

/// @brief Name of the User attribute 'Password'
const std::string STAMP_VALUE = "value";

/// @brief Name of the User attribute 'Password'
const std::string STAMP_CURRENCY = "currency";

/**
 * @brief The Stamp class
 */
class Stamp : public EntityBase
{
public:
    /// @brief The Stamp Pointer type
    typedef std::shared_ptr<Stamp> Pointer;

    /// @brief The Stamp constant Pointer type
    typedef std::shared_ptr<Stamp const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of Stamp
     * @return Return a Pointer to new instance of Stamp
     */
    static Pointer New();

    /**
     * @brief Create an instance of Stamp
     */
    Stamp();

    /**
     * @brief Destroy the instance of Stamp
     */
    virtual ~Stamp();

    /**
     * @brief Get the Stamp country
     * @return Return the Stamp country
     */
    Attribute<std::string>::Pointer get_country() const;

    /**
     * @brief Set the Stamp country
     * @param country: New Stamp country
     */
    void set_country(std::string const & country);

    /**
     * @brief Get the Stamp year
     * @return Return the Stamp year
     */
    Attribute<int>::Pointer get_year() const;

    /**
     * @brief Set the Stamp year
     * @param year: New Stamp year
     */
    void set_year(int year);

    /**
     * @brief Get the Stamp value
     * @return Return the Stamp value
     */
    Attribute<double>::Pointer get_value() const;

    /**
     * @brief Set the Stamp value
     * @param value: New Stamp value
     */
    void set_value(double value);

    /**
     * @brief Get the Stamp currency
     * @return Return the Stamp currency
     */
    Attribute<std::string>::Pointer get_currency() const;

    /**
     * @brief Set the Stamp currency
     * @param currency: New Stamp currency
     */
    void set_currency(std::string const & currency);

    /**
     * @brief Convert a JSON object into this Stamp
     * @param json: JSON object in which the entity is readed
     */
    virtual void from_json(QJsonObject const & json);

    /**
     * @brief Convert this Stamp as JSON attribute
     * @param json: JSON object in which the entity is added
     */
    virtual void to_json(QJsonObject & json) const;

    /**
     * @brief Fill this Stamp from another
     * @param other: Other Stamp
     */
    void patch_from_other(ConstPointer other);

protected:

private:
    /// @brief The stamp country
    Attribute<std::string>::Pointer _country;

    /// @brief The stamp year
    Attribute<int>::Pointer _year;

    /// @brief The stamp year
    Attribute<double>::Pointer _value;

    /// @brief The stamp currency
    Attribute<std::string>::Pointer _currency;

};

} // namespace model

} // namespace lib

} // namespace cams

#endif // _db4c988b_87fe_48a5_bf41_7ce5c8c04b79
