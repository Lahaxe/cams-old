#ifndef _5dc2942d_0163_4037_8904_9da7fed3b0cf
#define _5dc2942d_0163_4037_8904_9da7fed3b0cf

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
class ConnectionWidget;
}

class ConnectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionWidget(QWidget *parent = 0);

    virtual ~ConnectionWidget();

    void onConnectionRefused();

Q_SIGNALS:
    void sendConnection(QString const & login, QString const & password);

    void sendNewAccount(QString const & login);

    void sendResetPassword(QString const & login);

private slots:
    void on_newAccountButton_clicked();

    void on_ConnectionButton_clicked();

    void onResetPasswordClicked();

    void onLoginFilled(bool isFilled);

    void onPasswordFilled(bool isFilled);

private:
    Ui::ConnectionWidget * _ui;
};
/*
} // namespace connection

} // namespace gui

} // namespace cams
*/
#endif // _5dc2942d_0163_4037_8904_9da7fed3b0cf
