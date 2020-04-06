#ifndef _3589e03a_d642_4764_bf57_a807db675c56
#define _3589e03a_d642_4764_bf57_a807db675c56

// include Qt files
#include <QObject>

#include <iostream>

class FocusEventFilter : public QObject
{
    Q_OBJECT

public:
    explicit FocusEventFilter(QObject *parent = 0);

    virtual ~FocusEventFilter();

    virtual bool eventFilter(QObject * obj, QEvent * event) override;

Q_SIGNALS:
    void focusChanged(bool hasFocus);

private:

};

#endif // _3589e03a_d642_4764_bf57_a807db675c56
