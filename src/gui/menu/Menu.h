#ifndef _bc09e680_1ffe_4e01_bc22_9fde1b3070b2
#define _bc09e680_1ffe_4e01_bc22_9fde1b3070b2

// include Qt files
#include <QWidget>

/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{

/// @brief Menu part
namespace menu
{

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);

    virtual ~Menu();

private slots:
    void on_user_btn_clicked();

private:
    Ui::Menu * _ui;
};

} // namespace menu

} // namespace gui

} // namespace cams

#endif // _bc09e680_1ffe_4e01_bc22_9fde1b3070b2
