#ifndef _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc
#define _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc

// Include Project files
#include "model/core/EntityBase.h"

namespace libcams
{

namespace model
{

/**
 * @brief The User class
 */
class User : public EntityBase
{
public:
    /**
     * @brief Create an instance of EntityBase
     * @param id: The entity Identifier
     * @param name: The user name
     */
    User(std::string const & id = "", std::string const & name = "");

    /**
     * @brief Destructor
     */
    virtual ~User();

    /**
     * @brief Get the user name
     * @return Return the user name
     */
    std::string get_name() const;

    /**
     * @brief Set the user name
     * @param name: The user name
     */
    void set_name(std::string const & name);

protected:

private:
    /// The user name
    std::string _name;

};

} // namespace model

} // namespace libcams

#endif // _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc
