#ifndef _a8cd50cf_fe0b_49d1_86ea_1bdc6e42715d
#define _a8cd50cf_fe0b_49d1_86ea_1bdc6e42715d

// Include Project files
#include "model/core/EntityBase.h"

namespace libcams
{

namespace model
{

/**
 * @brief The User class
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
     * @param id: The entity Identifier
     */
    Token();

    /**
     * @brief Destructor
     */
    virtual ~Token();

    /**
     * @brief Get the user id
     * @return Return the user id
     */
    std::string get_userid() const;

    /**
     * @brief Set the user name
     * @param name: The user name
     */
    void set_userid(std::string const & userid);

    /**
     * @brief Get the user name
     * @return Return the user name
     */
    std::string get_username() const;

    /**
     * @brief Set the user name
     * @param name: The user name
     */
    void set_username(std::string const & username);

    /**
     * @brief Get the user token
     * @return Return the user token
     */
    std::string get_token() const;

    /**
     * @brief Set the user token
     * @param name: The user token
     */
    void set_token(std::string const & password);

    virtual void from_json(QJsonObject const & json);

    virtual void to_json(QJsonObject & json) const;

protected:

private:
    /// @brief The user id
    std::string _userid;

    /// @brief The user name
    std::string _username;

    /// @brief The user token
    std::string _token;

};

} // namespace model

} // namespace libcams

#endif // _a8cd50cf_fe0b_49d1_86ea_1bdc6e42715d
