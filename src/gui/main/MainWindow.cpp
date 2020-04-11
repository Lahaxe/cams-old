// Include Qt files
#include <QDesktopWidget>
#include <QFile>

// Include Project files
#include "controller/MainWidgetController.h"
#include "model/users/Identity.h"
#include "main/MainWindow.h"
#include "ui_MainWindow.h"

/*
/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{
*/
MainWindow
::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    this->_ui->setupUi(this);

    // Connect Signals
    this->connect(this->_ui->Connection, SIGNAL(connectionGranted()),
                  this, SLOT(onConnectionGranted()));
    this->connect(this->_ui->Connection, SIGNAL(sendResetPassword(QString const &)),
                  this, SLOT(onResetPasswordSend(QString const &)));
    this->connect(this->_ui->Connection, SIGNAL(sendNewAccount(QString const &)),
                  this, SLOT(onNewAccountSend(QString const &)));
    this->connect(this->_ui->CreateAccount, SIGNAL(sendBackToConnection(QString const &)),
                  this, SLOT(onSendBackToConnectionSend(QString const &)));

    this->connect(MainWidgetController::instance()->get_user_menu(), SIGNAL(disconnectClick()),
                  this, SLOT(onDisconnectClicked()));
}

MainWindow
::~MainWindow()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
MainWindow
::initialize()
{
    // Resize to fullscreen
    this->resize(QDesktopWidget().availableGeometry(this).size());
    this->_ui->centralwidget->setGeometry(0,0,this->size().width(), this->size().height());
    this->_ui->Main->setGeometry(0,0,this->size().width(), this->size().height());

    // Load stylesheet
    /*QFile stylesheet("cams.css");
    if (stylesheet.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        qApp->setStyleSheet(stylesheet.readAll());
        stylesheet.close();
    }
    else
    {
        // A revoir => Default stylesheet ???
    }*/

    // Initialize all widget
    this->_ui->Connection->initialize();
    this->_ui->CreateAccount->initialize();
    this->_ui->Main->initialize();

    this->_ui->Main->hide();
    this->_ui->CreateAccount->hide();
}

void
MainWindow
::onConnectionGranted()
{
    this->_ui->Connection->hide();
    // TODO ajouter l'user ID pour initialiser l'écran
    this->_ui->Main->show();
}

void
MainWindow
::onResetPasswordSend(QString const & __attribute__((unused))login)
{
    // Not implemented yet
}

void
MainWindow
::onNewAccountSend(const QString & login)
{
    this->_ui->Connection->hide();
    this->_ui->CreateAccount->set_login(login);
    this->_ui->CreateAccount->show();
}

void
MainWindow
::onSendBackToConnectionSend(QString const & login)
{
    this->_ui->CreateAccount->hide();
    this->_ui->Connection->set_login(login);
    this->_ui->Connection->show();
}

void
MainWindow
::onDisconnectClicked()
{
    this->_ui->Main->hide();

    auto identity = MainWidgetController::instance()->get_connector()->get_identity();
    identity->set_token(""); // Remove token
    this->_ui->Connection->set_login(QString(identity->get_login().c_str()));

    this->_ui->Connection->show();
}
/*
} // namespace gui

} // namespace cams
*/
