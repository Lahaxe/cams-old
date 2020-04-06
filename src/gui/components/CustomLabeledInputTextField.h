#ifndef _3e5c9467_8241_420f_9684_3f3d291682d7
#define _3e5c9467_8241_420f_9684_3f3d291682d7

// include Qt files
#include <QWidget>

/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{

/// @brief Components part
namespace components
{

namespace Ui {
class CustomLabeledInputTextField;
}

class CustomLabeledInputTextField : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString field_label READ get_field_label WRITE set_field_label DESIGNABLE true)

public:
    explicit CustomLabeledInputTextField(QWidget *parent = 0);

    virtual ~CustomLabeledInputTextField();

    QString get_field_label() const;

    void set_field_label(QString const & label);

private slots:

private:
    Ui::CustomLabeledInputTextField * _ui;

};

} // namespace components

} // namespace gui

} // namespace cams

#endif // _3e5c9467_8241_420f_9684_3f3d291682d7
