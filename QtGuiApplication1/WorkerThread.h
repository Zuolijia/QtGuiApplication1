#pragma once

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    WorkerThread(QObject *parent = 0);
    ~WorkerThread();

protected:
    void run();

signals:
    void done();
};
