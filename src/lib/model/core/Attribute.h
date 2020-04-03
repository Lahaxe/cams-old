#ifndef _b6c95c96_f0ec_4f3e_8880_6244820cd915
#define _b6c95c96_f0ec_4f3e_8880_6244820cd915

#include <memory>

namespace libcams
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

    static Pointer New();

    static Pointer New(const T& value);

    /**
     * @brief Create an instance of Attribute
     */
    Attribute();

    /**
     * @brief Create an instance of Attribute
     */
    Attribute(const T& value);

    /**
     * @brief Destructor
     */
    virtual ~Attribute();

    T get_value() const;

    void set_value(const T& value);

    bool is_set() const;

protected:

private:
    T _value;

    bool _is_set;

};

} // namespace model

} // namespace libcams

// Include template implementation
#include "model/core/Attribute.txx"

#endif // _b6c95c96_f0ec_4f3e_8880_6244820cd915
