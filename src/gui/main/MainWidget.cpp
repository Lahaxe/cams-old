// Include Project files
#include "main/MainWidget.h"
#include "ui_MainWidget.h"
#include "controller/MainWidgetController.h"

MainWidget
::MainWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::MainWidget)
{
    this->_ui->setupUi(this);

    MainWidgetController::instance()->set_user_menu(this->_ui->menu_user);
    MainWidgetController::instance()->set_dashboard(this->_ui->dashboard);
}

MainWidget
::~MainWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
MainWidget
::initialize()
{
    this->_ui->menu->setGeometry(0, 0, this->size().width(), 50);
    this->_ui->menu_user->setGeometry(this->size().width() - 210, 48, 210, 130);
    this->_ui->dashboard->setGeometry(0,50,this->size().width(), this->size().height() - 50);

    this->_ui->menu->initialize();
    this->_ui->dashboard->initialize();

    // This is the top widget
    this->_ui->menu_user->raise();

    this->_ui->menu_user->hide();
}

void MainWidget::mousePressEvent(QMouseEvent * __attribute__((unused))event)
{
    MainWidgetController::instance()->get_user_menu()->hide();
}
