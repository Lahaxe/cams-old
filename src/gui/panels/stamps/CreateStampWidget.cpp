// Include Project files
#include "panels/stamps/CreateStampWidget.h"
#include "ui_CreateStampWidget.h"
#include "controller/MainWidgetController.h"
#include "controller/ControllerFactory.h"
#include "controller/ControllerStamps.h"
#include "model/stamps/Stamp.h"

CreateStampWidget
::CreateStampWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::CreateStampWidget)
{
    this->_ui->setupUi(this);
}

CreateStampWidget
::~CreateStampWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
CreateStampWidget
::initialize()
{
}

void
CreateStampWidget
::on_createButton_clicked()
{
    // Create Stamp controller
    auto controller = cams::lib::controller::ControllerFactory::instance().create(
                cams::lib::controller::ControllerStamps::class_name());
    controller->set_connector(MainWidgetController::instance()->get_connector());

    auto stamp = cams::lib::model::Stamp::New();
    stamp->set_country("France");
    stamp->set_year(1990);
    stamp->set_value(0.59);

    QJsonObject json_stamp;
    stamp->to_json(json_stamp);

    auto result = controller->execute(cams::lib::controller::ACTION_POST, "", QJsonDocument(json_stamp));
}
