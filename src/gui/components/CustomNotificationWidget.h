#ifndef _b96a4625_8f9f_4171_b9f7_e83696f25270
#define _b96a4625_8f9f_4171_b9f7_e83696f25270

// include Qt files
#include <QWidget>

namespace Ui {
class CustomNotificationWidget;
}

class CustomNotificationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomNotificationWidget(QWidget *parent = 0);

    virtual ~CustomNotificationWidget();

    void showError(QString const & message);

    void showWarning(QString const & message);

    void showInformation(QString const & message);

private slots:
    void on_closeButton_clicked();

private slots:

private:
    Ui::CustomNotificationWidget * _ui;

};

#endif // _b96a4625_8f9f_4171_b9f7_e83696f25270
