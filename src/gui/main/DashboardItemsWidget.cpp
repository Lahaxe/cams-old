// Include Project files
#include "main/DashboardItemsWidget.h"
#include "ui_DashboardItemsWidget.h"
#include "controller/MainWidgetController.h"

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

void
DashboardItemsWidget
::on_createButton_clicked()
{
    MainWidgetController::instance()->get_dashboard()->create_add_panel();
}
