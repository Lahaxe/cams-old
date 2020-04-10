// Include Standard library files
#include <cstdlib>
#include <iostream>
#include <sstream>

// Include Qt files
#include <QApplication>

// Include Cams files
#include "common/configuration/Configuration.h"
#include "common/logger/Logger.h"
#include "common/logger/LoggerFactory.h"
#include "main/MainWindow.h"

int main(int argc, char *argv[])
{
    int exit_value = EXIT_SUCCESS;

    auto logger_type = cams::lib::common::Configuration::instance().get_logger_type();
    cams::lib::common::Logger::instance().set_logger_writer(
                cams::lib::common::LoggerFactory::instance().create(logger_type));
    cams::lib::common::LoggerFactory::delete_instance();

    try
    {
        std::stringstream message;
        message << "Begin " << std::string(argv[0]);
        cams::lib::common::Logger::instance().info(message.str());

        QApplication a(argc, argv);

        // Configure application
        QCoreApplication::setOrganizationName("RLahaxe");
        QCoreApplication::setApplicationName("cams-gui");

        // Create main frame
        MainWindow frame;
        frame.show();

        exit_value = a.exec();
    }
    catch (std::exception & exc)
    {
        exit_value = EXIT_FAILURE;

        std::stringstream message;
        message << exc.what();
        cams::lib::common::Logger::instance().fatal(message.str());
    }

    std::stringstream message;
    message << "End " << std::string(argv[0]);
    cams::lib::common::Logger::instance().info(message.str());

    cams::lib::common::Logger::delete_instance();
    cams::lib::common::Configuration::delete_instance();

    return exit_value;
}
