#ifndef _44b486d1_d56b_4633_99d5_bc2a882b9636
#define _44b486d1_d56b_4633_99d5_bc2a882b9636

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
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);

    virtual ~MainWidget();

    void initialize();

private slots:

private:
    Ui::MainWidget * _ui;

};
/*
} // namespace connection

} // namespace gui

} // namespace cams
*/
#endif // _44b486d1_d56b_4633_99d5_bc2a882b9636
