#pragma once

#include <QWidget>
#include <QtGui>

class ClipboardDemo : public QWidget
{
    Q_OBJECT

public:
    ClipboardDemo(QWidget *parent = 0);
    ~ClipboardDemo();

private slots:
    void setClipboardContent();
    void getClipboardContent();
};
