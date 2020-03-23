// Include Project files
#include "common/logger/Logger.h"
#include "User.h"
#include "ui_User.h"

User
::User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User
::~User()
{
    delete ui;
}

void
User
::on_quit_btn_clicked()
{
    // Close this window
    this->close();

    // Close the main window (and the application)
    foreach(QWidget *widget, qApp->topLevelWidgets())
    {
        if(widget->inherits("QMainWindow"))
        {
            widget->close();
        }
    }
}
