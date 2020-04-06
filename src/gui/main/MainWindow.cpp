// Include Qt files
#include <qdesktopwidget.h>
#include <QFile>

// Include Project files
#include "connector/ConnectorFactory.h"
#include "common/configuration/Configuration.h"
#include "common/exception/CamsException.h"
#include "controller/ControllerFactory.h"
#include "controller/ControllerToken.h"
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
    _ui(new Ui::MainWindow), _connector(nullptr)
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

    // Connect Signals
    this->connect(this->_ui->Connection, SIGNAL(sendConnection(QString const &, QString const &)),
                  this, SLOT(onConnectionSend(QString const &, QString const &)));

    // Create the connector
    this->_connector = cams::lib::connector::ConnectorFactory::instance().create(
                cams::lib::common::Configuration::instance().get_connector_type());
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
::onConnectionSend(const QString & login, const QString & password)
{
    this->_connector->set_identity(cams::lib::model::Identity::New(
                                       login.toStdString(), password.toStdString(), ""));

    // Create Token controller
    auto controller = cams::lib::controller::ControllerFactory::instance().create(
                cams::lib::controller::ControllerToken::class_name());
    controller->set_connector(this->_connector);

    try
    {
        // Send token request
        auto response = controller->execute(cams::lib::controller::ACTION_POST);

        // Parse response
        auto token = cams::lib::model::Token::New();
        token->from_json(response.object());

        if (!token->get_token().empty())
        {
            // Connection granted !!!
            this->_connector->get_identity()->set_token(token->get_token());
            this->_ui->Connection->hide();
            // TODO ajouter l'user ID pour initialiser l'écran
            //this->_ui->MainWidget->show();
            return;
        }
    }
    catch (cams::lib::common::CamsException const & exc)
    {
        // Nothing to do
        // A revoir => log an error
    }

    this->_ui->Connection->onConnectionRefused();
}
/*
} // namespace gui

} // namespace cams
*/
