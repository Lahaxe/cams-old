// include Qt files
#include <QEvent>

// Include Project files
#include "tools/FocusEventFilter.h"

FocusEventFilter
::FocusEventFilter(QObject * parent) :
    QObject(parent)
{
    if (parent != nullptr)
    {
        parent->installEventFilter(this);
    }
}

FocusEventFilter
::~FocusEventFilter()
{
    // Nothing to do
}

bool
FocusEventFilter
::eventFilter(QObject * obj, QEvent * event)
{
    if (event->type() == QEvent::FocusIn)
    {
        emit focusChanged(true);
    }
    else if (event->type() == QEvent::FocusOut)
    {
        emit focusChanged(false);
    }
    else
    {
        // Ignore other event
    }

    return QObject::eventFilter(obj, event);
}
