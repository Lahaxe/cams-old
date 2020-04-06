// Include Project files
#include "components/CustomLabeledInputTextField.h"
#include "tools/FocusEventFilter.h"
#include "ui_CustomLabeledInputTextField.h"

CustomLabeledInputTextField
::CustomLabeledInputTextField(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::CustomLabeledInputTextField)
{
    this->_ui->setupUi(this);

    this->_ui->message->setText("");

    auto focuseventfilter = new FocusEventFilter(this->_ui->inputText);
    this->connect(focuseventfilter, &FocusEventFilter::focusChanged,
                  this, &CustomLabeledInputTextField::fieldlabel_focusChanged);
}

CustomLabeledInputTextField
::~CustomLabeledInputTextField()
{
    if (this->_ui != nullptr)
    {
        delete this->_ui;
    }
}

QString
CustomLabeledInputTextField
::get_field_label() const
{
    return this->_ui->fieldLabel->text();
}

void
CustomLabeledInputTextField
::set_field_label(QString const & label)
{
    this->_ui->fieldLabel->setText(label);
}

QString
CustomLabeledInputTextField
::get_input() const
{
    return this->_ui->inputText->text();
}

void
CustomLabeledInputTextField
::display_error_message(QString const & message)
{
    this->_ui->message->setText(message);
}

void
CustomLabeledInputTextField
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
CustomLabeledInputTextField
::fieldlabel_focusChanged(bool has_focus)
{
    if (!has_focus && this->_ui->inputText->text().isEmpty())
    {
        this->display_error_message("This field is required.");
    }
}
