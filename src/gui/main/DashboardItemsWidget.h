#ifndef _cf8413c5_5402_4055_9ae6_6adf33b3a8ff
#define _cf8413c5_5402_4055_9ae6_6adf33b3a8ff

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
class DashboardItemsWidget;
}

class DashboardItemsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardItemsWidget(QWidget *parent = 0);

    virtual ~DashboardItemsWidget();

    void initialize();

private slots:
    void on_createButton_clicked();

private:
    Ui::DashboardItemsWidget * _ui;

};
/*
} // namespace connection

} // namespace gui

} // namespace cams
*/
#endif // _cf8413c5_5402_4055_9ae6_6adf33b3a8ff
