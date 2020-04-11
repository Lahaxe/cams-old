// Include Project files
#include "main/DashboardWidget.h"
#include "ui_DashboardWidget.h"

DashboardWidget
::DashboardWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::DashboardWidget)
{
    this->_ui->setupUi(this);
}

DashboardWidget
::~DashboardWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
DashboardWidget
::initialize()
{
}
