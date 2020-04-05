// Include Project files
#include "components/ValidationButton.h"

namespace cams
{

namespace gui
{

namespace components
{

ValidationButton
::ValidationButton(QWidget *parent) :
    QPushButton(parent)
{
    // Nothing to do
}

ValidationButton
::ValidationButton(const QString &text, QWidget *parent):
    QPushButton(text, parent)
{
    // Nothing to do
}

ValidationButton
::~ValidationButton()
{
    // Nothing to do
}

} // namespace components

} // namespace gui

} // namespace cams
