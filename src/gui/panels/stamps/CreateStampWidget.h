#ifndef _6957fda1_3279_481d_b37e_55ec23e74d89
#define _6957fda1_3279_481d_b37e_55ec23e74d89

// include Qt files
#include <QWidget>
/*
/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{

*/
namespace Ui {
class CreateStampWidget;
}

class CreateStampWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CreateStampWidget(QWidget *parent = 0);

    virtual ~CreateStampWidget();

    void initialize();

private slots:
    void on_createButton_clicked();

private:
    Ui::CreateStampWidget * _ui;

};
/*

} // namespace gui

} // namespace cams
*/
#endif // _6957fda1_3279_481d_b37e_55ec23e74d89
