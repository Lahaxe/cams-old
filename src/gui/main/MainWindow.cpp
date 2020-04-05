
// Include Qt files
#include <qdesktopwidget.h>

// Include Project files
#include "main/MainWindow.h"
#include "ui_MainWindow.h"

/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{

MainWindow
::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    this->_ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // Resize to fullscreen
    this->resize(QDesktopWidget().availableGeometry(this).size());
}

MainWindow
::~MainWindow()
{
    delete this->_ui;
}

} // namespace gui

} // namespace cams
