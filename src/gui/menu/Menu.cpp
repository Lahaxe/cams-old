// Include Qt files
#include <QMainWindow>

// Include Project files
#include "menu/Menu.h"
#include "ui_Menu.h"
#include "menu/UserMenuWidget.h"

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
::on_user_btn_clicked()
{
    auto usermenu = new UserMenuWidget(this);

    this->_ui->gridLayout->addWidget(usermenu);
}
