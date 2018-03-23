#include <QApplication>
#include <QDebug>
#include <QCoreApplication>
#include <QLabel>
#include <QMouseEvent>

#include "mainwindow.h"
#include "newspaper.h"
#include "reader.h"
#include "CustomButton.h"

class EventLabel :public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

void EventLabel::mouseMoveEvent(QMouseEvent *ev)
{
    this->setText(QString("<center><h1>Move:(%1,%2)</h1></center>")
        .arg(QString::number(ev->x()), QString::number(ev->y())));
}

void EventLabel::mousePressEvent(QMouseEvent *ev)
{
    this->setText(QString("<center><h1>Press:(%1,%2)</h1></center>")
        .arg(QString::number(ev->x()), QString::number(ev->y())));
}

void EventLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString msg;
    msg.sprintf("<center><h1>Release:(%d,%d)</h1></center>", ev->x(), ev->y());
    this->setText(msg);
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    MainWindow win;
    win.show();

    /*EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    label->setMouseTracking(true);
    label->show();*/

    /*CustomButton btn;
    btn.setText(QObject::tr("This is a Button"));
    btn.show();*/
	
	return app.exec();
}
