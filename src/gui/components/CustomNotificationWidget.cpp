// Include Project files
#include "components/CustomNotificationWidget.h"
#include "ui_CustomNotificationWidget.h"

CustomNotificationWidget
::CustomNotificationWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::CustomNotificationWidget)
{
    this->_ui->setupUi(this);
}

CustomNotificationWidget
::~CustomNotificationWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
CustomNotificationWidget
::showError(const QString &message)
{
    this->_ui->message->setText(message);
    // TODO => background error
    this->show();
}

void
CustomNotificationWidget
::on_closeButton_clicked()
{
    this->hide();
}
