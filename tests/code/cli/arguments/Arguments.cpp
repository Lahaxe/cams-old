#define BOOST_TEST_MODULE ModuleArguments

// Include Standard library
#include <iostream>

// Include Project files
#include "src/cli/arguments/MissingArgumentException.h"
#include "src/cli/arguments/UnknownArgumentException.h"
#include "tests/code/cli/arguments/FixtureArguments.h"

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureArguments)
{
    BOOST_CHECK(this->_arguments != nullptr);
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_FIXTURE_TEST_CASE(Accessors, FixtureArguments)
{
    BOOST_REQUIRE(this->_arguments != nullptr);

    BOOST_CHECK(this->_arguments->get_display_help() == false);
    this->_arguments->set_display_help(true);
    BOOST_CHECK(this->_arguments->get_display_help() == true);

    BOOST_CHECK_EQUAL(this->_arguments->get_action(), std::string("action"));
    this->_arguments->set_action("newaction");
    BOOST_CHECK_EQUAL(this->_arguments->get_action(), std::string("newaction"));

    BOOST_CHECK_EQUAL(this->_arguments->get_controller(), std::string("controller"));
    this->_arguments->set_controller("newcontroller");
    BOOST_CHECK_EQUAL(this->_arguments->get_controller(), std::string("newcontroller"));

    BOOST_CHECK_EQUAL(this->_arguments->get_user(), std::string("user"));
    this->_arguments->set_user("newuser");
    BOOST_CHECK_EQUAL(this->_arguments->get_user(), std::string("newuser"));

    BOOST_CHECK_EQUAL(this->_arguments->get_password(), std::string("password"));
    this->_arguments->set_password("newpassword");
    BOOST_CHECK_EQUAL(this->_arguments->get_password(), std::string("newpassword"));

    BOOST_CHECK_EQUAL(this->_arguments->get_token(), std::string("token"));
    this->_arguments->set_token("newtoken");
    BOOST_CHECK_EQUAL(this->_arguments->get_token(), std::string("newtoken"));

    BOOST_CHECK_EQUAL(this->_arguments->get_json_file(), std::string("json_file"));
    this->_arguments->set_json_file("newjson_file");
    BOOST_CHECK_EQUAL(this->_arguments->get_json_file(), std::string("newjson_file"));

    BOOST_CHECK_EQUAL(this->_arguments->get_json_string(), std::string("json_string"));
    this->_arguments->set_json_string("newjson_string");
    BOOST_CHECK_EQUAL(this->_arguments->get_json_string(), std::string("newjson_string"));

    BOOST_CHECK_EQUAL(this->_arguments->get_ressource_path(), std::string("ressource_path"));
    this->_arguments->set_ressource_path("newressource_path");
    BOOST_CHECK_EQUAL(this->_arguments->get_ressource_path(), std::string("newressource_path"));
}

/******************************** TEST Nominal ********************************/
/**
 * @brief Nominal test case: Tests Getters and Setters
 */
BOOST_AUTO_TEST_CASE(DisplayHelp)
{
    {
    int const count = 2;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char help[] = "-h";
    args[current_count] = help;

    auto arguments = cams::cli::Arguments(count, args);

    BOOST_CHECK(arguments.get_display_help() == true);
    }

    {
    int const count = 2;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char help[] = "--help";
    args[current_count] = help;

    auto arguments = cams::cli::Arguments(count, args);

    BOOST_CHECK(arguments.get_display_help() == true);
    }

    {
    int const count = 2;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char help[] = "help";
    args[current_count] = help;

    auto arguments = cams::cli::Arguments(count, args);

    BOOST_CHECK(arguments.get_display_help() == true);
    }

    {
    int const count = 4;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;
    ++current_count;

    char controller[] = "controller";
    args[current_count] = controller;
    ++current_count;

    char help[] = "-h";
    args[current_count] = help;

    auto arguments = cams::cli::Arguments(count, args);

    BOOST_CHECK(arguments.get_display_help() == true);
    }
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Missing 'Action' argument
 */
BOOST_AUTO_TEST_CASE(ErrorMissingAction)
{
    int const count = 1;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::MissingArgumentException,
                          [](cams::cli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Action");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Missing 'Controller' argument
 */
BOOST_AUTO_TEST_CASE(ErrorMissingController)
{
    int const count = 2;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::MissingArgumentException,
                          [](cams::cli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Controller");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Unknown argument
 */
BOOST_AUTO_TEST_CASE(ErrorUnknownArgument)
{
    int const count = 4;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;
    ++current_count;

    char controller[] = "controller";
    args[current_count] = controller;
    ++current_count;

    char unknown[] = "error";
    args[current_count] = unknown;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::UnknownArgumentException,
                          [](cams::cli::UnknownArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is unknown: error");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Missing argument User
 */
BOOST_AUTO_TEST_CASE(ErrorMissingArgumentUser)
{
    int const count = 4;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;
    ++current_count;

    char controller[] = "controller";
    args[current_count] = controller;
    ++current_count;

    char unknown[] = "-u";
    args[current_count] = unknown;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::MissingArgumentException,
                          [](cams::cli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: User");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Missing argument Password
 */
BOOST_AUTO_TEST_CASE(ErrorMissingArgumentPassword)
{
    int const count = 4;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;
    ++current_count;

    char controller[] = "controller";
    args[current_count] = controller;
    ++current_count;

    char unknown[] = "-p";
    args[current_count] = unknown;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::MissingArgumentException,
                          [](cams::cli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Password");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Missing argument Token
 */
BOOST_AUTO_TEST_CASE(ErrorMissingArgumentToken)
{
    int const count = 4;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;
    ++current_count;

    char controller[] = "controller";
    args[current_count] = controller;
    ++current_count;

    char unknown[] = "-t";
    args[current_count] = unknown;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::MissingArgumentException,
                          [](cams::cli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Token");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Missing argument JsonFile
 */
BOOST_AUTO_TEST_CASE(ErrorMissingArgumentJsonFile)
{
    int const count = 4;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;
    ++current_count;

    char controller[] = "controller";
    args[current_count] = controller;
    ++current_count;

    char unknown[] = "-f";
    args[current_count] = unknown;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::MissingArgumentException,
                          [](cams::cli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Jsonfile");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Missing argument JsonString
 */
BOOST_AUTO_TEST_CASE(ErrorMissingArgumentJsonString)
{
    int const count = 4;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;
    ++current_count;

    char controller[] = "controller";
    args[current_count] = controller;
    ++current_count;

    char unknown[] = "-j";
    args[current_count] = unknown;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::MissingArgumentException,
                          [](cams::cli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Json");
                                });
}

/******************************** TEST Error **********************************/
/**
 * @brief Error test case: Missing argument Ressource
 */
BOOST_AUTO_TEST_CASE(ErrorMissingArgumentJsonJsonRessource)
{
    int const count = 4;
    char* args[count];

    int current_count = 0;
    char program[] = "program";
    args[current_count] = program;
    ++current_count;

    char action[] = "action";
    args[current_count] = action;
    ++current_count;

    char controller[] = "controller";
    args[current_count] = controller;
    ++current_count;

    char unknown[] = "-r";
    args[current_count] = unknown;

    BOOST_CHECK_EXCEPTION(cams::cli::Arguments(count, args),
                          cams::cli::MissingArgumentException,
                          [](cams::cli::MissingArgumentException const & exc)
                                {
                                    return std::string(exc.what()) ==
                                            std::string("At least one argument is missing: Ressource");
                                });
}
