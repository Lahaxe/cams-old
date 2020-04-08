#ifndef _9162810b_73fd_4f92_9c12_53cff547cbcc
#define _9162810b_73fd_4f92_9c12_53cff547cbcc

// Include Qt Files
#include <QMainWindow>

#include "connector/ConnectorBase.h"
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

private slots:
    void onConnectionSend(QString const &, QString const &);

    void onResetPasswordSend(QString const &);

private:
    Ui::MainWindow * _ui;

    cams::lib::connector::ConnectorBase::Pointer _connector;

};
/*
} // namespace gui

} // namespace cams
*/
#endif // _9162810b_73fd_4f92_9c12_53cff547cbcc
