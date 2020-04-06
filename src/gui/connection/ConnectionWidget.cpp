// Include Qt files
#include <QMainWindow>

// Include Project files
#include "connection/ConnectionWidget.h"
#include "ui_ConnectionWidget.h"

namespace cams
{

namespace gui
{

namespace connection
{

ConnectionWidget
::ConnectionWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::ConnectionWidget)
{
    this->_ui->setupUi(this);

    this->_ui->errorMessage->resize(400, 50);
    this->_ui->login->resize(400, 50);
    this->_ui->password->resize(400, 50);


    this->_ui->login->set_field_label("Nom d'utilisateur");
    this->_ui->password->set_field_label("Mot de passe");
}

ConnectionWidget
::~ConnectionWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

} // namespace connection

} // namespace gui

} // namespace cams
