// Include Standard library
#include <cstdlib>
#include <iostream>
#include <sstream>

// Include
#include "common/logger/Logger.h"
#include "common/logger/DefaultLogger.h"
#include "common/logger/FileLogger.h"
#include "common/exception/CamsException.h"
#include "connector/ConnectorFactory.h"
#include "controller/ControllerFactory.h"
#include "controller/UnknownActionException.h"
#include "controller/UnknownControllerException.h"
#include "camscli/Arguments.h"

int main(int argc, char *argv[])
{
    auto exit_value = EXIT_SUCCESS;

    // Sortie standard
    //libcams::common::DefaultLogger::create_instance();

    // Fichier log
    libcams::common::FileLogger::create_instance();

    try
    {
        std::stringstream message;
        message << "Begin " << std::string(argv[0]);
        libcams::common::Logger::instance().info(message.str());

        libcams::camscli::Arguments arguments(argc, argv);

        if (arguments.get_display_help() == true)
        {
            // Display help
            std::cout << "Syntax: " << std::string(argv[0]) << " action controller [options]" << std::endl;
        }
        else
        {
            std::stringstream message;
            message << "Trying to " << arguments.get_action() << " " << arguments.get_controller();
            libcams::common::Logger::instance().info(message.str());

            // Check the controller
            if (!libcams::controller::ControllerFactory::instance().can_create(arguments.get_controller()))
            {
                throw libcams::controller::UnknownControllerException(arguments.get_controller());
            }

            // Create the controller
            auto controller = libcams::controller::ControllerFactory::instance().create(arguments.get_controller());

            // Check the action
            if (!controller->exists_action(arguments.get_action()))
            {
                throw libcams::controller::UnknownActionException(arguments.get_action());
            }

            // Add identity to the controller
            controller->set_identity(libcams::controller::Identity::New(
                        arguments.get_user(), arguments.get_password(), arguments.get_token()));

            // Create the connector
            controller->set_connector(libcams::connector::ConnectorFactory::instance().create("file"));

            // Execute the action
            auto response = controller->execute(arguments.get_action());

            libcams::common::Logger::instance().info(response);
        }
    }
    catch (std::exception & exc)
    {
        exit_value = EXIT_FAILURE;

        std::stringstream message;
        message << exc.what();
        libcams::common::Logger::instance().fatal(message.str());
    }

    libcams::controller::ControllerFactory::delete_instance();

    std::stringstream message;
    message << "End " << std::string(argv[0]);
    libcams::common::Logger::instance().info(message.str());

    libcams::common::Logger::delete_instance();

    return exit_value;
}

