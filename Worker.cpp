#include "Worker.h"
#include <QDebug.h>
#include <QThread>
#include <qtimer.h>
#include <QApplication.h>
#include <qvariant.h>
#include <qmetaobject.h>
#include "ProgressEvent.h"

const int  kMaxNumber = 100000000;
Worker::Worker(QObject* receiver) : m_receiver(receiver)
{
	qDebug() << "Create Worker run method running in thread : " << QThread::currentThread();

}

Worker::~Worker()
{
	qDebug() << "Destroy Worker run method running in thread : " << QThread::currentThread();

}

void Worker::run()
{
	qDebug() << "Worker run method running in thread : " << QThread::currentThread();
	
	/*
	QTimer* timer = new QTimer();
	QObject::connect(timer, &QTimer::timeout, []() {
		
	});
	timer->setInterval(1000);
	timer->start();
	*/

	/*
	for (int i{0}; i < kMaxNumber; i++)
	{
		if ((i % 10000) == 0)
		{
			double percentage = ((static_cast<double>(i) / static_cast<double>(kMaxNumber))) * 100;
			//qDebug() << "Current percentage : " << percentage;
			//Option 1 [postevent]			
			//QApplication::postEvent(m_receiver, new ProgressEvent(QVariant::fromValue(percentage).toInt()));

			//Option 2 [metaObject]
			QMetaObject::invokeMethod(m_receiver, 
				"gotUpdate", 
				Qt::QueuedConnection, 
				Q_ARG(int, QVariant::fromValue(percentage).toInt())
			);

		}
	}
	*/
}
