#ifndef _f0a9ee97_83a8_4aa1_be9d_432ad9054c1c
#define _f0a9ee97_83a8_4aa1_be9d_432ad9054c1c

// Include Standard library
#include <string>

namespace libcams
{

namespace camscli
{

class Arguments
{
public:
    Arguments(int argc, char *argv[]);

    virtual ~Arguments();

    bool get_display_help() const;

    void set_display_help(bool display_help);

    std::string get_action() const;

    void set_action(std::string const & action);

    std::string get_controller() const;

    void set_controller(std::string const & controller);

    std::string get_user() const;

    void set_user(std::string const & user);

    std::string get_password() const;

    void set_password(std::string const & password);

    std::string get_token() const;

    void set_token(std::string const & token);

    std::string get_json_file() const;

    void set_json_file(std::string const & json_file);

    std::string get_json_string() const;

    void set_json_string(std::string const & json_string);

    std::string get_ressource_path() const;

    void set_ressource_path(std::string const & ressource_path);

protected:

private:
    bool _display_help;

    std::string _action;

    std::string _controller;

    std::string _user;

    std::string _password;

    std::string _token;

    std::string _json_file;

    std::string _json_string;

    std::string _ressource_path;

    void _parse(int argc, char *argv[]);

};

} // namespace camscli

} // namespace libcams

#endif // _f0a9ee97_83a8_4aa1_be9d_432ad9054c1c
