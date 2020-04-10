// Include Qt files
#include <QMainWindow>

// Include Project files
#include "menu/UserMenuWidget.h"
#include "ui_UserMenuWidget.h"

UserMenuWidget
::UserMenuWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::UserMenuWidget)
{
    this->_ui->setupUi(this);
}

UserMenuWidget
::~UserMenuWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

