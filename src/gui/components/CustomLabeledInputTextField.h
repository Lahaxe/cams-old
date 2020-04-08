#ifndef _3e5c9467_8241_420f_9684_3f3d291682d7
#define _3e5c9467_8241_420f_9684_3f3d291682d7

// include Qt files
#include <QWidget>

namespace Ui {
class CustomLabeledInputTextField;
}

class CustomLabeledInputTextField : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString field_label READ get_field_label WRITE set_field_label DESIGNABLE true)

public:
    explicit CustomLabeledInputTextField(QWidget *parent = 0);

    virtual ~CustomLabeledInputTextField();

    QString get_field_label() const;

    void set_field_label(QString const & label);

    QString get_input() const;

    void set_input(QString const & input);

    void display_error_message(QString const & message);

Q_SIGNALS:
    void inputFill(bool isFilled);

private slots:
    void on_inputText_textChanged(const QString &arg1);

    void fieldlabel_focusChanged(bool has_focus);

private:
    Ui::CustomLabeledInputTextField * _ui;

};

#endif // _3e5c9467_8241_420f_9684_3f3d291682d7
