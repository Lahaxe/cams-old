// Include Project files
#include "main/DashboardWidget.h"
#include "ui_DashboardWidget.h"
#include "panels/stamps/CreateStampWidget.h"

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
    this->_ui->addwidget->setGeometry(10, 10, this->size().width() / 2, this->size().height() / 2);
}

void DashboardWidget::create_add_panel()
{
    auto panel = new CreateStampWidget(this);
    this->layout()->addWidget(panel);
}
