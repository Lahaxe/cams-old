// Include Project files
#include "main/DashboardItemsWidget.h"
#include "ui_DashboardItemsWidget.h"

DashboardItemsWidget
::DashboardItemsWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::DashboardItemsWidget)
{
    this->_ui->setupUi(this);
}

DashboardItemsWidget
::~DashboardItemsWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
DashboardItemsWidget
::initialize()
{
}
