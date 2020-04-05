// Include Qt files
#include <qdesktopwidget.h>
#include <QFile>

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

    // Resize to fullscreen
    this->resize(QDesktopWidget().availableGeometry(this).size());

    // Load stylesheet
    QFile stylesheet("cams.css");
    if (stylesheet.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        qApp->setStyleSheet(stylesheet.readAll());
        stylesheet.close();
    }
    else
    {
        // A revoir => Default stylesheet ???
    }

    // Hide menu
    this->_ui->widget->hide();
}

MainWindow
::~MainWindow()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

} // namespace gui

} // namespace cams
