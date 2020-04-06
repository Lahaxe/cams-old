// Include Qt files
#include <QMainWindow>

// Include Project files
#include "connection/ConnectionWidget.h"
#include "ui_ConnectionWidget.h"

ConnectionWidget
::ConnectionWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::ConnectionWidget)
{
    this->_ui->setupUi(this);

    this->_ui->errorMessage->resize(400, 50);
    this->_ui->errorMessage->hide();
    this->_ui->login->resize(400, 50);
    this->_ui->password->resize(400, 50);

    this->connect(this->_ui->login, SIGNAL(inputFill(bool)), this, SLOT(onLoginFilled(bool)));
    this->connect(this->_ui->password, SIGNAL(inputFill(bool)), this, SLOT(onPasswordFilled(bool)));


    this->_ui->login->set_field_label("Nom d'utilisateur");
    this->_ui->password->set_field_label("Mot de passe");
}

ConnectionWidget
::~ConnectionWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
ConnectionWidget
::onConnectionRefused()
{
    // Display error
    this->_ui->errorMessage->show();
}

void
ConnectionWidget
::on_ConnectionButton_clicked()
{
    emit sendConnection(this->_ui->login->get_input(),
                        this->_ui->password->get_input());
}

void
ConnectionWidget
::onLoginFilled(bool isFilled)
{
    this->_ui->ConnectionButton->setEnabled(isFilled && !this->_ui->password->get_input().isEmpty());
}

void
ConnectionWidget
::onPasswordFilled(bool isFilled)
{
    this->_ui->ConnectionButton->setEnabled(isFilled && !this->_ui->login->get_input().isEmpty());
}
