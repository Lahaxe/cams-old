// Include Qt files
#include <QMainWindow>

// Include Project files
#include "main/MainWidget.h"
#include "ui_MainWidget.h"

MainWidget
::MainWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::MainWidget)
{
    this->_ui->setupUi(this);
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
    this->_ui->menu->setGeometry(0,0,this->size().width(), 50);
}
