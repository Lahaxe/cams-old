#ifndef _19a21ca3_9285_476f_abcb_d418b4faef8e
#define _19a21ca3_9285_476f_abcb_d418b4faef8e

// include Qt files
#include <QWidget>
/*
/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{

/// @brief Connection part
namespace connection
{
*/
namespace Ui {
class DashboardWidget;
}

class DashboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardWidget(QWidget *parent = 0);

    virtual ~DashboardWidget();

    void initialize();

private:
    Ui::DashboardWidget * _ui;

};
/*
} // namespace connection

} // namespace gui

} // namespace cams
*/
#endif // _19a21ca3_9285_476f_abcb_d418b4faef8e
