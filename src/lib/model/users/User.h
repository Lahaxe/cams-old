#ifndef _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc
#define _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc

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
const std::string USER_NAME = "name";

/// @brief Name of the User attribute 'Password'
const std::string USER_PASSWORD = "password";

/**
 * @brief The User class
 */
class User : public EntityBase
{
public:
    /// @brief The User Pointer type
    typedef std::shared_ptr<User> Pointer;

    /// @brief The User constant Pointer type
    typedef std::shared_ptr<User const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of User
     * @return Return a Pointer to new instance of User
     */
    static Pointer New();

    /**
     * @brief Create an instance of User
     */
    User();

    /**
     * @brief Destroy the instance of User
     */
    virtual ~User();

    /**
     * @brief Get the User name
     * @return Return the User name
     */
    Attribute<std::string>::Pointer get_name() const;

    /**
     * @brief Set the User name
     * @param name: New User name
     */
    void set_name(std::string const & name);

    /**
     * @brief Get the User password
     * @return Return the User password
     */
    Attribute<std::string>::Pointer get_password() const;

    /**
     * @brief Set the User password
     * @param name: New User password
     */
    void set_password(std::string const & password);

    /**
     * @brief Convert a JSON object into this EntityBase
     * @param json: JSON object in which the entity is readed
     */
    virtual void from_json(QJsonObject const & json);

    /**
     * @brief Convert this EntityBase as JSON attribute
     * @param json: JSON object in which the entity is added
     */
    virtual void to_json(QJsonObject & json) const;

    /**
     * @brief Fill this User from another
     * @param other: Other User
     */
    void patch_from_other(ConstPointer other);

protected:

private:
    /// @brief The user name
    Attribute<std::string>::Pointer _name;

    /// @brief The user password
    Attribute<std::string>::Pointer _password;

};

} // namespace model

} // namespace lib

} // namespace cams

#endif // _785f3a4a_bd4b_4116_a2f2_5bbd9c2fb9fc
