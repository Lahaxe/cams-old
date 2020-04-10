// Include Project files
#include "controller/MainWidgetController.h"

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
::MainWidgetController()
{
}

MainWidgetController
::~MainWidgetController()
{
}

/*
} // namespace gui

} // namespace cams
*/
