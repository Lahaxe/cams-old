#ifndef _f0a9ee97_83a8_4aa1_be9d_432ad9054c1c
#define _f0a9ee97_83a8_4aa1_be9d_432ad9054c1c

// Include Standard library
#include <string>

/// @brief Main namespace
namespace cams
{

namespace cli
{

/**
 * @brief The Arguments class
 */
class Arguments
{
public:
    /**
     * @brief Contructor
     * @param argc: Number of arguments
     * @param argv: List of arguments
     */
    Arguments(int argc, char *argv[]);

    /**
     * @brief Destructor
     */
    virtual ~Arguments();

    /**
     * @brief Get diplay_help member
     * @return Return value of display_help
     */
    bool get_display_help() const;

    /**
     * @brief Set display_help member
     * @param display_help: New value of display_help
     */
    void set_display_help(bool display_help);

    /**
     * @brief Get action member
     * @return Return value of action
     */
    std::string get_action() const;

    /**
     * @brief Set action member
     * @param display_help: New value of action
     */
    void set_action(std::string const & action);

    /**
     * @brief Get controller member
     * @return Return value of controller
     */
    std::string get_controller() const;

    /**
     * @brief Set controller member
     * @param display_help: New value of controller
     */
    void set_controller(std::string const & controller);

    /**
     * @brief Get user member
     * @return Return value of user
     */
    std::string get_user() const;

    /**
     * @brief Set user member
     * @param display_help: New value of user
     */
    void set_user(std::string const & user);

    /**
     * @brief Get password member
     * @return Return value of password
     */
    std::string get_password() const;

    /**
     * @brief Set password member
     * @param display_help: New value of password
     */
    void set_password(std::string const & password);

    /**
     * @brief Get token member
     * @return Return value of token
     */
    std::string get_token() const;

    /**
     * @brief Set token member
     * @param display_help: New value of token
     */
    void set_token(std::string const & token);

    /**
     * @brief Get json_file member
     * @return Return value of json_file
     */
    std::string get_json_file() const;

    /**
     * @brief Set json_file member
     * @param display_help: New value of json_file
     */
    void set_json_file(std::string const & json_file);

    /**
     * @brief Get json_string member
     * @return Return value of json_string
     */
    std::string get_json_string() const;

    /**
     * @brief Set json_string member
     * @param display_help: New value of json_string
     */
    void set_json_string(std::string const & json_string);

    /**
     * @brief Get ressource_path member
     * @return Return value of ressource_path
     */
    std::string get_ressource_path() const;

    /**
     * @brief Set ressource_path member
     * @param display_help: New value of ressource_path
     */
    void set_ressource_path(std::string const & ressource_path);

protected:

private:
    /// @brief Indicate if argument Help is present
    bool _display_help;

    /// @brief Value of argument Action
    std::string _action;

    /// @brief Value of argument Controller
    std::string _controller;

    /// @brief Value of argument User
    std::string _user;

    /// @brief Value of argument Password
    std::string _password;

    /// @brief Value of argument Token
    std::string _token;

    /// @brief Value of argument JsonFile
    std::string _json_file;

    /// @brief Value of argument JsonString
    std::string _json_string;

    /// @brief Value of argument Ressource path
    std::string _ressource_path;

    /**
     * @brief Parse the input arguments
     * @param argc: Number of arguments
     * @param argv: List of arguments
     */
    void _parse(int argc, char *argv[]);

};

} // namespace cli

} // namespace cams

#endif // _f0a9ee97_83a8_4aa1_be9d_432ad9054c1c
