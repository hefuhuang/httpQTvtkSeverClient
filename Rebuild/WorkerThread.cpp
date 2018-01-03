#include "WorkerThread.h"

WorkerThread::WorkerThread(QObject *parent)
	: QThread(parent)
{
}

WorkerThread::~WorkerThread()
{
}


void WorkerThread::Run()
{
	for (int i = 0; i < 1000000000; i++);
	emit Done(); 

} 

