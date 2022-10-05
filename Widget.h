#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"


class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void on_startButton_clicked();

    void on_infoButton_clicked();

public slots:
    void gotUpdate(int value);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() override;
    
    bool event(QEvent* event) override;

private:
    Ui::WidgetClass ui;   

};
