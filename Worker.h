#pragma once

#include <QObject>
#include <QRunnable.h>

class Worker  : public QRunnable
{	

public:
	Worker(QObject* receiver);
	~Worker() override;

	void run() override;
private:
	QObject* m_receiver;
};
