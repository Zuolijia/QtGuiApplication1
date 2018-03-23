#include "CustomButton.h"

CustomButton::CustomButton(QWidget *parent)
    : QPushButton(parent)
{
    connect(this, &CustomButton::clicked,
        this, &CustomButton::onButtonCliecked);
}

CustomButton::~CustomButton()
{
}

void CustomButton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        qDebug() << "left";
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}

void CustomButton::onButtonCliecked()
{
    qDebug() << "You clicked this!";
}
