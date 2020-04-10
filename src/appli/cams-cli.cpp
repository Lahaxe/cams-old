// Include Standard library
#include <cstdlib>
#include <iostream>
#include <sstream>

// Include Cams files
#include "common/configuration/Configuration.h"
#include "common/logger/Logger.h"
#include "common/logger/LoggerFactory.h"
#include "common/exception/CamsException.h"
#include "connector/ConnectorFactory.h"
#include "controller/ControllerFactory.h"
#include "controller/UnknownActionException.h"
#include "controller/UnknownControllerException.h"
#include "arguments/Arguments.h"

int main(int argc, char *argv[])
{
    auto exit_value = EXIT_SUCCESS;

    auto logger_type = cams::lib::common::Configuration::instance().get_logger_type();
    cams::lib::common::Logger::instance().set_logger_writer(
                cams::lib::common::LoggerFactory::instance().create(logger_type));
    cams::lib::common::LoggerFactory::delete_instance();

    try
    {
        std::stringstream message;
        message << "Begin " << std::string(argv[0]);
        cams::lib::common::Logger::instance().info(message.str());

        cams::cli::Arguments arguments(argc, argv);

        if (arguments.get_display_help() == true)
        {
            // Display help
            std::cout << "Syntax: " << std::string(argv[0]) << " action controller [options]" << std::endl;
        }
        else
        {
            std::stringstream message;
            message << "Trying to " << arguments.get_action() << " " << arguments.get_controller();
            cams::lib::common::Logger::instance().info(message.str());

            // Check the controller
            if (!cams::lib::controller::ControllerFactory::instance().can_create(arguments.get_controller()))
            {
                throw cams::lib::controller::UnknownControllerException(arguments.get_controller());
            }

            // Create the controller
            auto controller = cams::lib::controller::ControllerFactory::instance().create(arguments.get_controller());

            // Check the action
            if (!controller->exists_action(arguments.get_action()))
            {
                throw cams::lib::controller::UnknownActionException(arguments.get_action());
            }

            // Create the connector
            controller->set_connector(cams::lib::connector::ConnectorFactory::instance().create(
                                          cams::lib::common::Configuration::instance().get_connector_type()));

            // Add identity to the connector
            controller->get_connector()->set_identity(cams::lib::model::Identity::New(
                        arguments.get_user(), arguments.get_password(), arguments.get_token()));

            auto document = QJsonDocument::fromJson(QByteArray(arguments.get_json_string().c_str()));

            // Execute the action
            auto response = controller->execute(arguments.get_action(), arguments.get_ressource_path(), document);

            auto result = response.toJson().toStdString();
            cams::lib::common::Logger::instance().info(result);
            std::cout << result << std::endl;
        }
    }
    catch (cams::lib::common::CamsException & camsexc)
    {
        exit_value = EXIT_FAILURE;

        auto message = camsexc.to_json();
        cams::lib::common::Logger::instance().fatal(message);

        std::cout << message << std::endl;
    }
    catch (std::exception & exc)
    {
        exit_value = EXIT_FAILURE;

        std::stringstream message;
        message << exc.what();
        cams::lib::common::Logger::instance().fatal(message.str());
    }

    cams::lib::connector::ConnectorFactory::delete_instance();
    cams::lib::controller::ControllerFactory::delete_instance();

    std::stringstream message;
    message << "End " << std::string(argv[0]);
    cams::lib::common::Logger::instance().info(message.str());

    cams::lib::common::Logger::delete_instance();
    cams::lib::common::Configuration::delete_instance();

    return exit_value;
}

