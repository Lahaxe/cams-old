// Include Project files
#include "components/CustomLabeledInputPasswordField.h"
#include "tools/FocusEventFilter.h"
#include "ui_CustomLabeledInputPasswordField.h"

CustomLabeledInputPasswordField
::CustomLabeledInputPasswordField(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::CustomLabeledInputPasswordField)
{
    this->_ui->setupUi(this);

    this->_ui->message->setText("");

    auto focuseventfilter = new FocusEventFilter(this->_ui->inputText);
    this->connect(focuseventfilter, &FocusEventFilter::focusChanged,
                  this, &CustomLabeledInputPasswordField::fieldlabel_focusChanged);
}

CustomLabeledInputPasswordField
::~CustomLabeledInputPasswordField()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

QString
CustomLabeledInputPasswordField
::get_field_label() const
{
    return this->_ui->fieldLabel->text();
}

void
CustomLabeledInputPasswordField
::set_field_label(QString const & label)
{
    this->_ui->fieldLabel->setText(label);
}

QString
CustomLabeledInputPasswordField
::get_input() const
{
    return this->_ui->inputText->text();
}

void
CustomLabeledInputPasswordField
::display_error_message(QString const & message)
{
    this->_ui->message->setText(message);
}

void
CustomLabeledInputPasswordField
::on_inputText_textChanged(const QString &arg1)
{
    if (!arg1.isEmpty())
    {
        this->_ui->message->setText("");
        emit this->inputFill(true);
    }
    else
    {
        this->display_error_message("This field is required.");
        emit this->inputFill(false);
    }
}

void
CustomLabeledInputPasswordField
::fieldlabel_focusChanged(bool has_focus)
{
    if (!has_focus && this->_ui->inputText->text().isEmpty())
    {
        this->display_error_message("This field is required.");
    }
}

void
CustomLabeledInputPasswordField
::on_forgetPasswordButton_clicked()
{

}
