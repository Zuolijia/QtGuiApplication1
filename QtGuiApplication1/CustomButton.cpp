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

void CustomButton::onButtonCliecked()
{
    qDebug() << "You clicked this!";
}
