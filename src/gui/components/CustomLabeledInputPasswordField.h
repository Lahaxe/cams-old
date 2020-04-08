#ifndef _92b53077_2ae5_4412_86c3_ee9b5ceae483
#define _92b53077_2ae5_4412_86c3_ee9b5ceae483

// include Qt files
#include <QWidget>

namespace Ui {
class CustomLabeledInputPasswordField;
}

class CustomLabeledInputPasswordField : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString field_label READ get_field_label WRITE set_field_label DESIGNABLE true)

public:
    explicit CustomLabeledInputPasswordField(QWidget *parent = 0);

    virtual ~CustomLabeledInputPasswordField();

    QString get_field_label() const;

    void set_field_label(QString const & label);

    QString get_input() const;

    void display_error_message(QString const & message);

    void enabled_forgetpassword_button(bool is_enabled);

Q_SIGNALS:
    void inputFill(bool isFilled);

    void requestNewPassword();

private slots:
    void on_forgetPasswordButton_clicked();

private slots:
    void on_inputText_textChanged(const QString &arg1);

    void fieldlabel_focusChanged(bool has_focus);

private:
    Ui::CustomLabeledInputPasswordField * _ui;

};

#endif // _92b53077_2ae5_4412_86c3_ee9b5ceae483
