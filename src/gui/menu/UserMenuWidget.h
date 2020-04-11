#ifndef _077033ef_ed17_43fd_9102_47548156160e
#define _077033ef_ed17_43fd_9102_47548156160e

// include Qt files
#include <QWidget>
/*
/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{

/// @brief Menu part
namespace menu
{
*/
namespace Ui {
class UserMenuWidget;
}

class UserMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserMenuWidget(QWidget *parent = 0);

    virtual ~UserMenuWidget();

Q_SIGNALS:
    void disconnectClick();

private slots:
    void on_disconnectButton_clicked();

private:
    Ui::UserMenuWidget * _ui;
};
/*
} // namespace menu

} // namespace gui

} // namespace cams
*/
#endif // _077033ef_ed17_43fd_9102_47548156160e
