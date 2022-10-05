#include "Widget.h"
#include "Worker.h"
#include <QThreadPool>
#include <qthread.h>
#include <QDebug>
#include <QEvent>
#include "ProgressEvent.h"

Worker* worker;

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    ui.setupUi(this);
    
    qDebug() << "Ui thread : " << QThread::currentThread();

}

Widget::~Widget()
{
    //delete worker;
}

bool Widget::event(QEvent* event)
{
    if (event->type() == static_cast<QEvent::Type>(ProgressEvent::EventId))
    {
        ProgressEvent* progressEvent = static_cast<ProgressEvent*>(event);
        //qDebug() << "Widget, progress is: " << progressEvent->progress();        
        ui.progressBar->setValue(progressEvent->progress());
        return true;
    }
    return QWidget::event(event);
}

void Widget::on_startButton_clicked(){
    worker = new Worker(this);
    QThreadPool::globalInstance()->start(worker); //automaticaly calls the destructor
    //worker->run();
}

void Widget::on_infoButton_clicked() {
    qDebug() << "ThreadPool max thread count : " << QThreadPool::globalInstance()->maxThreadCount();
    qDebug() << "Ideal thread count : " << QThread::idealThreadCount();
}   

void Widget::gotUpdate(int value) {
    ui.progressBar->setValue(value);
}
