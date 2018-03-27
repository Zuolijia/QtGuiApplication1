#include "WorkerThread.h"

WorkerThread::WorkerThread(QObject *parent)
    : QThread(parent)
{
}

WorkerThread::~WorkerThread()
{
}

void WorkerThread::run()
{
    for (int i = 0; i < 1000000000000000; ++i);
    sleep(5);
    emit done();
}
