// Include Project files
#include "components/CustomLabeledInputTextField.h"
#include "ui_CustomLabeledInputTextField.h"

namespace cams
{

namespace gui
{

namespace components
{

CustomLabeledInputTextField
::CustomLabeledInputTextField(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::CustomLabeledInputTextField)
{
    this->_ui->setupUi(this);
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

} // namespace components

} // namespace gui

} // namespace cams
