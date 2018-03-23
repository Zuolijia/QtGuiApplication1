#pragma once

#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>

class CustomButton : public QPushButton
{
    Q_OBJECT

public:
    CustomButton(QWidget *parent = 0);
    ~CustomButton();

protected:
    void mousePressEvent(QMouseEvent *e);

private:
    void onButtonCliecked();
};
