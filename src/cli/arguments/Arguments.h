#ifndef _f0a9ee97_83a8_4aa1_be9d_432ad9054c1c
#define _f0a9ee97_83a8_4aa1_be9d_432ad9054c1c

// Include Standard library
#include <string>

/// @brief Main namespace
namespace cams
{

/// @brief Cams Command Line Interface part
namespace cli
{

/**
 * @brief The Arguments class
 */
class Arguments
{
public:
    /**
     * @brief Create an instance of Arguments
     * @param argc: Number of arguments
     * @param argv: List of arguments
     */
    Arguments(int argc, char *argv[]);

    /**
     * @brief Destroy the instance of Arguments
     */
    virtual ~Arguments();

    /**
     * @brief Get the Argument display_help
     * @return Return the Argument display_help
     */
    bool get_display_help() const;

    /**
     * @brief Set the Argument display_help
     * @param display_help: New Argument display_help
     */
    void set_display_help(bool display_help);

    /**
     * @brief Get the Argument action
     * @return Return the Argument action
     */
    std::string get_action() const;

    /**
     * @brief Set the Argument action
     * @param action: New Argument action
     */
    void set_action(std::string const & action);

    /**
     * @brief Get the Argument controller
     * @return Return the Argument controller
     */
    std::string get_controller() const;

    /**
     * @brief Set the Argument controller
     * @param controller: New Argument controller
     */
    void set_controller(std::string const & controller);

    /**
     * @brief Get the Argument user
     * @return Return the Argument user
     */
    std::string get_user() const;

    /**
     * @brief Set the Argument user
     * @param user: New Argument user
     */
    void set_user(std::string const & user);

    /**
     * @brief Get the Argument password
     * @return Return the Argument password
     */
    std::string get_password() const;

    /**
     * @brief Set the Argument password
     * @param password: New Argument password
     */
    void set_password(std::string const & password);

    /**
     * @brief Get the Argument token
     * @return Return the Argument token
     */
    std::string get_token() const;

    /**
     * @brief Set the Argument token
     * @param token: New Argument token
     */
    void set_token(std::string const & token);

    /**
     * @brief Get the Argument json_file
     * @return Return the Argument json_file
     */
    std::string get_json_file() const;

    /**
     * @brief Set the Argument json_file
     * @param json_file: New Argument json_file
     */
    void set_json_file(std::string const & json_file);

    /**
     * @brief Get the Argument json_string
     * @return Return the Argument json_string
     */
    std::string get_json_string() const;

    /**
     * @brief Set the Argument json_string
     * @param json_string: New Argument json_string
     */
    void set_json_string(std::string const & json_string);

    /**
     * @brief Get the Argument ressource_path
     * @return Return the Argument ressource_path
     */
    std::string get_ressource_path() const;

    /**
     * @brief Set the Argument ressource_path
     * @param ressource_path: New Argument ressource_path
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
