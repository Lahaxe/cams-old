#ifndef _a525f584_8b2e_4449_a2f2_5f8873530512
#define _a525f584_8b2e_4449_a2f2_5f8873530512

// Include Standard library
#include <memory>

namespace cams
{

namespace lib
{

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
     * @return Return Pointer to new instance of Identity
     */
    static Pointer New(std::string const & login = "",
                       std::string const & password = "",
                       std::string const & token = "");

    /**
     * @brief Destructor
     */
    virtual ~Identity();

    /**
     * @brief Get login member
     * @return Return value of login
     */
    std::string get_login() const;

    /**
     * @brief Set login member
     * @param login: New value of login
     */
    void set_login(std::string const & login);

    /**
     * @brief Get password member
     * @return Return value of password
     */
    std::string get_password() const;

    /**
     * @brief Set password member
     * @param password: New value of password
     */
    void set_password(std::string const & password);

    /**
     * @brief Get token member
     * @return Return value of token
     */
    std::string get_token() const;

    /**
     * @brief Set token member
     * @param token: New value of token
     */
    void set_token(std::string const & token);

protected:

private:
    /**
     * @brief Create an instance of Identity
     */
    Identity(std::string const & login = "",
             std::string const & password = "",
             std::string const & token = "");

    /// @brief Login
    std::string _login;

    /// @brief Password
    std::string _password;

    /// @brief Token
    std::string _token;

};

}

}

}

#endif // _a525f584_8b2e_4449_a2f2_5f8873530512
