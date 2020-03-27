// Include Standard library
#include <cstdlib>
#include <iostream>
#include <sstream>

// Include
#include "common/logger/Logger.h"
#include "common/exception/CamsException.h"
#include "camscli/Arguments.h"

int main(int argc, char *argv[])
{
    auto exit_value = EXIT_SUCCESS;

    auto logger = libcams::common::Logger::instance();
    try
    {
        std::stringstream message;
        message << "Begin " << std::string(argv[0]);
        logger.info(message.str());

        std::stringstream syntax;
        syntax << std::string(argv[0]) << " action controller [options]";

        libcams::camscli::Arguments arguments(argc, argv);

        if (arguments.get_display_help() == true)
        {
            // Display help
            std::cout << "Syntax: " << syntax.str() << std::endl;
        }
        else
        {

            std::stringstream message;
            message << "Trying to " << arguments.get_action() << " " << arguments.get_controller();
            logger.info(message.str());

        }
    }
    catch (std::exception & exc)
    {
        exit_value = EXIT_FAILURE;

        std::stringstream message;
        message << exc.what();
        logger.fatal(message.str());
    }

    std::stringstream message;
    message << "End " << std::string(argv[0]);
    logger.info(message.str());

    libcams::common::Logger::delete_instance();

    return exit_value;
}

