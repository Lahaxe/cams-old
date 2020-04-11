// Include Project files
#include "menu/Menu.h"
#include "ui_Menu.h"
#include "controller/MainWidgetController.h"

Menu
::Menu(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Menu)
{
    this->_ui->setupUi(this);
}

Menu
::~Menu()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
Menu
::initialize()
{
    this->_ui->menu_btn->hide();
    this->_ui->notification_btn->hide();
}

void
Menu
::on_user_btn_clicked()
{
    MainWidgetController::instance()->get_user_menu()->show();
}
