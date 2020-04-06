#ifndef _95b29a3c_6459_48e0_b63f_736ffc5b59a5
#define _95b29a3c_6459_48e0_b63f_736ffc5b59a5

// include Qt files
#include <QPushButton>
/*
/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{

/// @brief Components part
namespace components
{
*/
class ValidationButton : public QPushButton
{
    Q_OBJECT

public:
    ValidationButton(QWidget *parent = Q_NULLPTR);

    ValidationButton(const QString &text, QWidget *parent = Q_NULLPTR);

    virtual ~ValidationButton();

private slots:

private:

};
/*
} // namespace components

} // namespace gui

} // namespace cams
*/
#endif // _95b29a3c_6459_48e0_b63f_736ffc5b59a5
