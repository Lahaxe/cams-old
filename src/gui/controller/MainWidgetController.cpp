// Include Project files
#include "controller/MainWidgetController.h"
#include "connector/ConnectorFactory.h"
#include "common/configuration/Configuration.h"

/*
/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{
*/

MainWidgetController * MainWidgetController::_instance = nullptr;

MainWidgetController *
MainWidgetController
::instance()
{
    if (MainWidgetController::_instance == nullptr)
    {
        MainWidgetController::_instance = new MainWidgetController();
    }
    return MainWidgetController::_instance;
}

void
MainWidgetController
::delete_instance()
{
    if (MainWidgetController::_instance != nullptr)
    {
        delete MainWidgetController::_instance;
        MainWidgetController::_instance = nullptr;
    }
}

MainWidgetController
::MainWidgetController():
    _connector(nullptr), _main_window(nullptr), _user_menu(nullptr)
{
    // Create the connector
    this->_connector = cams::lib::connector::ConnectorFactory::instance().create(
                cams::lib::common::Configuration::instance().get_connector_type());
}

MainWidgetController
::~MainWidgetController()
{
    if (this->_main_window != nullptr)
    {
        delete this->_main_window;
    }
}

cams::lib::connector::ConnectorBase::Pointer
MainWidgetController
::get_connector() const
{
    return this->_connector;
}

void
MainWidgetController
::create_main_window()
{
    this->_main_window = new MainWindow();
    this->_main_window->initialize();
    this->_main_window->show();
}

void
MainWidgetController
::set_user_menu(UserMenuWidget * user_menu)
{
    this->_user_menu = user_menu;
}

UserMenuWidget *
MainWidgetController
::get_user_menu() const
{
    return this->_user_menu;
}

void
MainWidgetController
::set_dashboard(DashboardWidget *dashboard)
{
    this->_dashboard = dashboard;
}

DashboardWidget *
MainWidgetController::
get_dashboard() const
{
    return this->_dashboard;
}

/*
} // namespace gui

} // namespace cams
*/
