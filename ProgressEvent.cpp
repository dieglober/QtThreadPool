#include "ProgressEvent.h"

ProgressEvent::ProgressEvent(int progress) : QEvent(static_cast<Type>(EventId)),
m_progress(progress)
{

}

ProgressEvent::~ProgressEvent()
{
    qDebug() << "Destroy ProgressEvent";
}

int ProgressEvent::progress() const
{
    return m_progress;
}
