// Include Qt files
#include <QMainWindow>

// Include Project files
#include "menu/Menu.h"
#include "ui_Menu.h"

Menu
::Menu(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Menu)
{
    this->_ui->setupUi(this);
    //this->resize(parent->size().width(), 60);
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
    // Nothing yet
}
