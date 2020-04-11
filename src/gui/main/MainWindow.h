#ifndef _9162810b_73fd_4f92_9c12_53cff547cbcc
#define _9162810b_73fd_4f92_9c12_53cff547cbcc

// Include Qt Files
#include <QMainWindow>
/*
/// @brief Main namespace
namespace cams
{

/// @brief Cams User Interface part
namespace gui
{
*/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    virtual ~MainWindow();

    void initialize();

private slots:
    void onConnectionGranted();

    void onResetPasswordSend(QString const &);

    void onNewAccountSend(QString const &);

    void onSendBackToConnectionSend(QString const &);

    void onDisconnectClicked();

private:
    Ui::MainWindow * _ui;

};
/*
} // namespace gui

} // namespace cams
*/
#endif // _9162810b_73fd_4f92_9c12_53cff547cbcc
