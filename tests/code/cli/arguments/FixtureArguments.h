#ifndef _1d4da5e6_5f16_4e41_bea7_da787d780f32
#define _1d4da5e6_5f16_4e41_bea7_da787d780f32

// Include Project files
#include "tests/code/FixtureBase.h"
#include "src/cli/arguments/Arguments.h"

class FixtureArguments : public FixtureBase
{
public:
    FixtureArguments(): FixtureBase(), _arguments(nullptr)
    {
        int const count = 15;
        char* arguments[count];

        int current_count = 0;
        char program[] = "program";
        arguments[current_count] = program;
        ++current_count;

        char action[] = "action";
        arguments[current_count] = action;
        ++current_count;

        char controller[] = "controller";
        arguments[current_count] = controller;
        ++current_count;

        char is_user[] = "-u";
        arguments[current_count] = is_user;
        ++current_count;

        char user[] = "user";
        arguments[current_count] = user;
        ++current_count;

        char is_pwd[] = "-p";
        arguments[current_count] = is_pwd;
        ++current_count;

        char pwd[] = "password";
        arguments[current_count] = pwd;
        ++current_count;

        char is_token[] = "-t";
        arguments[current_count] = is_token;
        ++current_count;

        char token[] = "token";
        arguments[current_count] = token;
        ++current_count;

        char is_jsonfile[] = "-f";
        arguments[current_count] = is_jsonfile;
        ++current_count;

        char jsonfile[] = "json_file";
        arguments[current_count] = jsonfile;
        ++current_count;

        char is_jsonstring[] = "-j";
        arguments[current_count] = is_jsonstring;
        ++current_count;

        char jsonstring[] = "json_string";
        arguments[current_count] = jsonstring;
        ++current_count;

        char is_ressource[] = "-r";
        arguments[current_count] = is_ressource;
        ++current_count;

        char ressource[] = "ressource_path";
        arguments[current_count] = ressource;
        ++current_count;

        this->_arguments = new cams::cli::Arguments(count, arguments);
    }

    virtual ~FixtureArguments()
    {
        if (this->_arguments != nullptr)
        {
            delete this->_arguments;
        }
    }

protected:
    cams::cli::Arguments* _arguments;

private:

};

#endif // _1d4da5e6_5f16_4e41_bea7_da787d780f32
