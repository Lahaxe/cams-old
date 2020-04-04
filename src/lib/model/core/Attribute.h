#ifndef _b6c95c96_f0ec_4f3e_8880_6244820cd915
#define _b6c95c96_f0ec_4f3e_8880_6244820cd915

// Include Standard library files
#include <memory>
#include <string>

// Include Qt files
#include <QJsonObject>

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Data Model
namespace model
{

/**
 * @brief The template class Attribute
 */
template<typename T>
class Attribute
{
public:
    /// @brief The Attribute Pointer type
    typedef std::shared_ptr<Attribute<T> > Pointer;

    /// @brief The Attribute constant Pointer type
    typedef std::shared_ptr<Attribute<T> const> ConstPointer;

    /**
     * @brief Create Pointer to a new instance of Attribute
     * @param name: Name of the Attribute
     * @return Return a Pointer to a new instance of Attribute
     */
    static Pointer New(std::string const & name);

    /**
     * @brief Create Pointer to a new instance of Attribute
     * @param name: Name of the Attribute
     * @tparam value: Value of the Attribute
     * @return Return a Pointer to a new instance of Attribute
     */
    static Pointer New(std::string const & name, const T& value);

    /**
     * @brief Create an instance of Attribute
     * @param name: Name of the Attribute
     */
    Attribute(std::string const & name);

    /**
     * @brief Create an instance of Attribute
     * @param name: Name of the Attribute
     * @tparam value: Value of the Attribute
     */
    Attribute(std::string const & name, const T& value);

    /**
     * @brief Destroy the instance of Attribute
     */
    virtual ~Attribute();

    /**
     * @brief Get the Attribute Name
     * @return Return the Attribute Name
     */
    std::string get_name() const;

    /**
     * @brief Set the Attribute Name
     * @param name: New Attribute Name
     */
    void set_name(std::string const & name);

    /**
     * @brief Get the Attribute Value
     * @return Return the Attribute Value
     */
    T get_value() const;

    /**
     * @brief Set the Attribute Value
     * @param value: New Attribute Value
     */
    void set_value(const T& value);

    /**
     * @brief Test wether the Attribute value is set
     * @return Return true if Attribute value is set, false otherwise
     */
    bool is_set() const;

    /**
     * @brief Convert a JSON object into this Attribute
     * @param json: JSON object in which the attribute is readed
     */
    void from_json(QJsonObject const & json);

    /**
     * @brief Convert this Attribute as JSON attribute
     * @param json: JSON object in which the attribute is added
     */
    void to_json(QJsonObject & json) const;

    /**
     * @brief Fill this attribute from another
     * @param other: Other attribute
     */
    void patch_from_other(ConstPointer other);

protected:

private:
    /// @brief Name of the Attribute
    std::string _name;

    /// @brief Value of the Attribute
    T _value;

    /// @brief Flag indicating if Attribute is set (True), or not (False)
    bool _is_set;

};


template<>
inline void
Attribute<std::string>
::from_json(QJsonObject const & json)
{
    if (json.contains(QString(this->_name.c_str())))
    {
        this->set_value(json[QString(this->_name.c_str())].toString().toStdString());
    }
}

template<>
inline void
Attribute<int>
::from_json(QJsonObject const & json)
{
    if (json.contains(QString(this->_name.c_str())))
    {
        this->set_value(json[QString(this->_name.c_str())].toInt());
    }
}

template<>
inline void
Attribute<bool>
::from_json(QJsonObject const & json)
{
    if (json.contains(QString(this->_name.c_str())))
    {
        this->set_value(json[QString(this->_name.c_str())].toBool());
    }
}

template<>
inline void
Attribute<double>
::from_json(QJsonObject const & json)
{
    if (json.contains(QString(this->_name.c_str())))
    {
        this->set_value(json[QString(this->_name.c_str())].toDouble());
    }
}

template<>
inline void
Attribute<std::string>
::to_json(QJsonObject & json) const
{
    if (this->_is_set)
    {
        json[QString(this->_name.c_str())] = QString(this->_value.c_str());
    }
}

} // namespace model

} // namespace lib

} // namespace cams

// Include template implementation
#include "model/core/Attribute.txx"

#endif // _b6c95c96_f0ec_4f3e_8880_6244820cd915
