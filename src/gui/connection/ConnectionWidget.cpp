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
