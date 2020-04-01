// Include Standard library
#include <cstdlib>
#include <iostream>
#include <sstream>

// Include
#include "common/configuration/Configuration.h"
#include "common/logger/Logger.h"
#include "common/logger/LoggerFactory.h"
#include "common/exception/CamsException.h"
#include "connector/ConnectorFactory.h"
#include "controller/ControllerFactory.h"
#include "controller/UnknownActionException.h"
#include "controller/UnknownControllerException.h"
#include "camscli/Arguments.h"

int main(int argc, char *argv[])
{
    auto exit_value = EXIT_SUCCESS;

    auto logger_type = libcams::common::Configuration::instance().get_logger_type();
    libcams::common::Logger::instance().set_logger_writer(
                libcams::common::LoggerFactory::instance().create(logger_type));
    libcams::common::LoggerFactory::delete_instance();

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

            // Create the connector
            controller->set_connector(libcams::connector::ConnectorFactory::instance().create(
                                          libcams::common::Configuration::instance().get_connector_type()));

            // Add identity to the connector
            controller->get_connector()->set_identity(libcams::model::Identity::New(
                        arguments.get_user(), arguments.get_password(), arguments.get_token()));

            // Execute the action
            auto response = controller->execute(arguments.get_action());

            auto result = response.toJson().toStdString();
            libcams::common::Logger::instance().info(result);
            std::cout << result << std::endl;
        }
    }
    catch (libcams::common::CamsException & camsexc)
    {
        exit_value = EXIT_FAILURE;

        auto message = camsexc.to_json();
        libcams::common::Logger::instance().fatal(message);

        std::cout << message << std::endl;
    }
    catch (std::exception & exc)
    {
        exit_value = EXIT_FAILURE;

        std::stringstream message;
        message << exc.what();
        libcams::common::Logger::instance().fatal(message.str());
    }

    libcams::connector::ConnectorFactory::delete_instance();
    libcams::controller::ControllerFactory::delete_instance();

    std::stringstream message;
    message << "End " << std::string(argv[0]);
    libcams::common::Logger::instance().info(message.str());

    libcams::common::Logger::delete_instance();
    libcams::common::Configuration::delete_instance();

    return exit_value;
}

