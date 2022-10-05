#pragma once
#include <QDebug>
#include <QEvent>

class ProgressEvent  : public QEvent
{	

public:
	enum {EventId = QEvent::User +1};
	ProgressEvent(int progress = 0);
	~ProgressEvent();
	int progress() const;
private:
	int m_progress;
};
