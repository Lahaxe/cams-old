#ifndef _2042560f_85db_421b_87f7_edb1a566b5b3
#define _2042560f_85db_421b_87f7_edb1a566b5b3

// Include Standard library
#include <memory>
#include <vector>

// Include Project files
#include "model/users/Identity.h"
#include "model/users/Token.h"
#include "model/users/User.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams library part
namespace lib
{

/// @brief Connector part
namespace connector
{

/**
 * @brief The ConnectorBase class
 */
class ConnectorBase
{
public:
    /// @brief The ConnectorBase Pointer type
    typedef std::shared_ptr<ConnectorBase> Pointer;

    /// @brief The ConnectorBase constant Pointer type
    typedef std::shared_ptr<ConnectorBase const> ConstPointer;

    /**
     * @brief Create an instance of ConnectorBase
     */
    ConnectorBase();

    /**
     * @brief Destroy the instance of ConnectorBase
     */
    virtual ~ConnectorBase();

    /**
     * @brief Get the ConnectorBase identity
     * @return Return the ConnectorBase identity
     */
    model::Identity::Pointer get_identity() const;

    /**
     * @brief Set the ConnectorBase identity
     * @param password: New ConnectorBase identity
     */
    void set_identity(model::Identity::Pointer identity);

    /**
     * @brief Allows to authenticate
     * @return Returns a token if authentication was successful
     */
    virtual model::Token::Pointer authenticate() = 0;

    /**
     * @brief Get all users
     * @return Returns list of users
     */
    virtual std::vector<model::User::Pointer> get_users() = 0;

    /**
     * @brief Get user by a given id
     * @param id: User id
     * @return Returns user corresponding to the given id
     */
    virtual model::User::Pointer get_user_by_id(std::string const & id) = 0;

    /**
     * @brief Create a new user
     * @param user: User to create
     */
    virtual void post_user(model::User::Pointer user) = 0;

    /**
     * @brief Replace an user
     * @param user: User to replace
     */
    virtual void put_user(model::User::Pointer user) = 0;

    /**
     * @brief Modify an user
     * @param user: User to modify
     */
    virtual void patch_user(model::User::Pointer user) = 0;

    /**
     * @brief Deletes an user by a given id
     * @param id: User id
     * @return Returns the deleted user
     */
    virtual model::User::Pointer delete_user_by_id(std::string const & id) = 0;

protected:

private:
    /// @brief The ConnectorBase identity
    model::Identity::Pointer _identity;

    /**
     * @brief Copy constructor (Purposely not implemented)
     * @param other: Object to copy
     */
    ConnectorBase(ConnectorBase const & other);

    /**
     * @brief operator = (Purposely not implemented)
     * @param other: Object to copy
     * @return Return a copy of a given ControllerBase
     */
    ConnectorBase& operator=(ConnectorBase const & other);

};

} // namespace connector

} // namespace lib

} // namespace cams

#endif // _2042560f_85db_421b_87f7_edb1a566b5b3
