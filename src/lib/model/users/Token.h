#ifndef _a8cd50cf_fe0b_49d1_86ea_1bdc6e42715d
#define _a8cd50cf_fe0b_49d1_86ea_1bdc6e42715d

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

/// @brief Name of the Token attribute 'User ID'
const std::string TOKEN_USERID= "userid";

/// @brief Name of the Token attribute 'User Name'
const std::string TOKEN_USERNAME = "username";

/// @brief Name of the Token attribute 'Token'
const std::string TOKEN_TOKEN = "token";

/**
 * @brief The Token class
 */
class Token : public EntityBase
{
public:
    /// @brief The Token Pointer type
    typedef std::shared_ptr<Token> Pointer;

    /// @brief The Token constant Pointer type
    typedef std::shared_ptr<Token const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of Token
     * @return Return Pointer to new instance of Token
     */
    static Pointer New();

    /**
     * @brief Create an instance of Token
     */
    Token();

    /**
     * @brief Destroy the instance of Token
     */
    virtual ~Token();

    /**
     * @brief Get the Token userid
     * @return Return the Token userid
     */
    std::string get_userid() const;

    /**
     * @brief Set the Token userid
     * @param login: New Token userid
     */
    void set_userid(std::string const & userid);

    /**
     * @brief Get the Token username
     * @return Return the Token username
     */
    std::string get_username() const;

    /**
     * @brief Set the Token username
     * @param login: New Token username
     */
    void set_username(std::string const & username);

    /**
     * @brief Get the Token token
     * @return Return the Token token
     */
    std::string get_token() const;

    /**
     * @brief Set the Token token
     * @param login: New Token token
     */
    void set_token(std::string const & token);

    /**
     * @brief Convert a JSON object into this Token
     * @param json: JSON object in which the token is readed
     */
    virtual void from_json(QJsonObject const & json);

    /**
     * @brief Convert this Token as JSON attribute
     * @param json: JSON object in which the token is added
     */
    virtual void to_json(QJsonObject & json) const;

protected:

private:
    /// @brief The user id
    Attribute<std::string>::Pointer _userid;

    /// @brief The user name
    Attribute<std::string>::Pointer _username;

    /// @brief The user token
    Attribute<std::string>::Pointer _token;

};

} // namespace model

} // namespace lib

} // namespace cams

#endif // _a8cd50cf_fe0b_49d1_86ea_1bdc6e42715d
