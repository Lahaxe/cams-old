// Include Qt files
#include <QMainWindow>

// Include Project files
#include "menu/Menu.h"
#include "ui_Menu.h"

namespace cams
{

namespace gui
{

namespace menu
{

Menu
::Menu(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::Menu)
{
    this->_ui->setupUi(this);
}

Menu
::~Menu()
{
    delete this->_ui;
}

void
Menu
::on_user_btn_clicked()
{
    // Nothing yet
}

} // namespace menu

} // namespace gui

} // namespace cams
