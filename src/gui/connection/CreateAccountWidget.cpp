// Include Project files
#include "connection/CreateAccountWidget.h"
#include "ui_CreateAccountWidget.h"

CreateAccountWidget
::CreateAccountWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::CreateAccountWidget)
{
    this->_ui->setupUi(this);

    this->_ui->errorMessage->resize(400, 50);
    this->_ui->errorMessage->hide();

    this->_ui->login->set_field_label("Nom d'utilisateur");
    this->_ui->password->set_field_label("Mot de passe");
    this->_ui->confirmPassword->set_field_label("Confirmation du mot de passe");
    this->_ui->mail->set_field_label("Adresse email");
}

CreateAccountWidget
::~CreateAccountWidget()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

void
CreateAccountWidget
::set_login(const QString &login)
{
    this->_ui->login->set_input(login);
}


void
CreateAccountWidget
::on_connectionButton_clicked()
{
    emit sendBackToConnection(this->_ui->login->get_input());
}
