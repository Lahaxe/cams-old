#ifndef _b96a4625_8f9f_4171_b9f7_e83696f25270
#define _b96a4625_8f9f_4171_b9f7_e83696f25270

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
class CustomNotificationWidget;
}

class CustomNotificationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomNotificationWidget(QWidget *parent = 0);

    virtual ~CustomNotificationWidget();

private slots:

private:
    Ui::CustomNotificationWidget * _ui;

};

} // namespace components

} // namespace gui

} // namespace cams

#endif // _b96a4625_8f9f_4171_b9f7_e83696f25270
