#pragma once

#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT

public:
    CustomButton(QWidget *parent = 0);
    ~CustomButton();

private:
    void onButtonCliecked();
};
