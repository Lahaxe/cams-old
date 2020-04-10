#ifndef _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c
#define _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c

//Include Project files
#include "connector/ConnectorBase.h"

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
 * @brief The ConnectorFile class
 */
class ConnectorFile : public ConnectorBase
{
public:
    /// @brief The ConnectorFile Pointer type
    typedef std::shared_ptr<ConnectorFile> Pointer;

    /// @brief The ConnectorFile constante Pointer type
    typedef std::shared_ptr<ConnectorFile const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of ConnectorFile
     * @return Return Pointer to new instance of ConnectorFile
     */
    static Pointer New();

    /**
     * @brief Destroy the instance of ConnectorFile
     */
    virtual ~ConnectorFile();

    /**
     * @brief Return the name of this class
     * @return Return name of this class
     */
    static std::string class_name();

    /**
     * @brief Allows to authenticate
     * @return Returns a token if authentication was successful
     */
    virtual model::Token::Pointer authenticate();

    /**
     * @brief Get all users
     * @return Returns list of users
     */
    virtual std::vector<model::User::Pointer> get_users();

    /**
     * @brief Get user by a given id
     * @param id: User id
     * @return Returns user corresponding to the given id
     */
    virtual model::User::Pointer get_user_by_id(std::string const & id);

    /**
     * @brief Create a new user
     * @param user: User to create
     */
    virtual void post_user(model::User::Pointer user);

    /**
     * @brief Replace an user
     * @param user: User to replace
     */
    virtual void put_user(model::User::Pointer user);

    /**
     * @brief Modify an user
     * @param user: User to modify
     */
    virtual void patch_user(model::User::Pointer user);

    /**
     * @brief Deletes an user by a given id
     * @param id: User id
     * @return Returns the deleted user
     */
    virtual model::User::Pointer delete_user_by_id(std::string const & id);

protected:

private:
    /**
     * @brief Create an instance of ConnectorFile
     */
    ConnectorFile();

    /**
     * @brief Copy constructor: purposely not implemented
     * @param other: Object to copy
     */
    ConnectorFile(ConnectorFile const & other);

    /**
     * @brief operator =: purposely not implemented
     * @param other: Object to copy
     */
    ConnectorFile& operator=(ConnectorFile const & other);

    /**
     * @brief Generates a new Token
     * @param userid: User id
     * @return Returns the new Token
     */
    std::string _generate_token(std::string const & userid) const;

    /**
     * @brief Verify the token
     * @param token: Token to verify
     * @return Returns true if token is a good one, false otherwise
     */
    bool _is_good_token(std::string const & token) const;

};

} // namespace connector

} // namespace lib

} // namespace cams

#endif // _ca947e3d_ec65_42f8_8ceb_a2d673b76e6c
