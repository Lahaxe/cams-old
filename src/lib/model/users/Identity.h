#ifndef _a525f584_8b2e_4449_a2f2_5f8873530512
#define _a525f584_8b2e_4449_a2f2_5f8873530512

// Include Standard library files
#include <memory>

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
 * @brief The Identity class
 */
class Identity
{
public:
    /// @brief The Identity Pointer type
    typedef std::shared_ptr<Identity> Pointer;

    /// @brief The Identity constant Pointer type
    typedef std::shared_ptr<Identity const> ConstPointer;

    /**
     * @brief Create pointer to a new instance of Identity
     * @return Return a Pointer to new instance of Identity
     */
    static Pointer New(std::string const & login = "",
                       std::string const & password = "",
                       std::string const & token = "");

    /**
     * @brief Destroy the instance of Identity
     */
    virtual ~Identity();

    /**
     * @brief Get the Identity login
     * @return Return the Identity login
     */
    std::string get_login() const;

    /**
     * @brief Set the Identity login
     * @param login: New Identity login
     */
    void set_login(std::string const & login);

    /**
     * @brief Get the Identity password
     * @return Return the Identity password
     */
    std::string get_password() const;

    /**
     * @brief Set the Identity password
     * @param password: New Identity password
     */
    void set_password(std::string const & password);

    /**
     * @brief Get the Identity token
     * @return Return the Identity token
     */
    std::string get_token() const;

    /**
     * @brief Set the Identity token
     * @param token: New Identity token
     */
    void set_token(std::string const & token);

protected:

private:
    /**
     * @brief Create an instance of Identity
     * @param login: User login
     * @param password: Password associated to the login
     * @param token: User token
     */
    Identity(std::string const & login = "",
             std::string const & password = "",
             std::string const & token = "");

    /// @brief User login
    std::string _login;

    /// @brief Password associated to the login
    std::string _password;

    /// @brief User token
    std::string _token;

};

} // namespace model

} // namespace lib

} // namespace cams

#endif // _a525f584_8b2e_4449_a2f2_5f8873530512
