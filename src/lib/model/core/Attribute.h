#ifndef _b6c95c96_f0ec_4f3e_8880_6244820cd915
#define _b6c95c96_f0ec_4f3e_8880_6244820cd915

// Include Standard files
#include <memory>
#include <string>

// Include Qt files
#include <QJsonObject>

namespace cams
{

namespace lib
{

namespace model
{

/**
 * @brief The template class Attribute
 */
template<typename T>
class Attribute
{
public:
    /// @brief The EntityBase Pointer type
    typedef std::shared_ptr<Attribute<T> > Pointer;

    /// @brief The EntityBase constant Pointer type
    typedef std::shared_ptr<Attribute<T> const> ConstPointer;

    static Pointer New(std::string const & name);

    static Pointer New(std::string const & name, const T& value);

    /**
     * @brief Create an instance of Attribute
     */
    Attribute(std::string const & name);

    /**
     * @brief Create an instance of Attribute
     */
    Attribute(std::string const & name, const T& value);

    /**
     * @brief Destructor
     */
    virtual ~Attribute();

    std::string get_name() const;

    void set_name(std::string const & name);

    T get_value() const;

    void set_value(const T& value);

    bool is_set() const;

    void from_json(QJsonObject const & json);

    void to_json(QJsonObject & json) const;

    void patch_from_other(ConstPointer other);

protected:

private:
    std::string _name;

    T _value;

    bool _is_set;

};

} // namespace model

}

} // namespace cams

// Include template implementation
#include "model/core/Attribute.txx"

#endif // _b6c95c96_f0ec_4f3e_8880_6244820cd915
