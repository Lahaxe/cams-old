#ifndef _389c55c6_afcb_41f2_8591_22801620eef3
#define _389c55c6_afcb_41f2_8591_22801620eef3

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
class CreateAccountWidget;
}

class CreateAccountWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccountWidget(QWidget *parent = 0);

    virtual ~CreateAccountWidget();

    void set_login(QString const & login);

private:
    Ui::CreateAccountWidget * _ui;
};
/*
} // namespace connection

} // namespace gui

} // namespace cams
*/
#endif // _389c55c6_afcb_41f2_8591_22801620eef3
