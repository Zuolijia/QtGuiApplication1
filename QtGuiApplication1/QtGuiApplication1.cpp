#include "QtGuiApplication1.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QDebug>

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout;
    ui.centralWidget->setLayout(layout);

    lcdNumber = new QLCDNumber(this);
    layout->addWidget(lcdNumber);

    QPushButton *button = new QPushButton(tr("Start"), this);
    layout->addWidget(button);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        qDebug() << "Time out";
        static int sec = 0;
        lcdNumber->display(QString::number(++sec)); 
    });

    WorkerThread *thread = new WorkerThread(this);
    //connect(thread, &WorkerThread::done, timer, &QTimer::stop);
    connect(thread, &WorkerThread::done, [=]() {
        timer->stop();
        button->setEnabled(true);
    });
    connect(thread, &WorkerThread::finished, [&]() {
        thread->deleteLater();
        thread = new WorkerThread(this);
    } );
    connect(button, &QPushButton::clicked, [=]() {
        button->setEnabled(false);
        timer->start(1);
        thread->start();
    });
}
