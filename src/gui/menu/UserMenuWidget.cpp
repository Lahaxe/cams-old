// Include Qt files
#include <QMessageBox>

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


void
UserMenuWidget
::on_disconnectButton_clicked()
{
    auto response = QMessageBox::question(this, "Log out", "Are you sure ?", QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes)
    {
        emit disconnectClick();
    }
}
