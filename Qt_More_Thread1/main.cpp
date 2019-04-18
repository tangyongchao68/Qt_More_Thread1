#include <QtCore/QCoreApplication>

#include <mythread.h>
#include <QDebug>
#include <QMutex>
#include <QThread>


#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*线程初始化*/
	/*
	MyThread *thread1;
	thread1 = new MyThread;
	thread1->start();
	qDebug() << "Main Thread id：" << QThread::currentThreadId();

	while (1)
	{
		qDebug() << "111==" << QThread::currentThreadId();
		_sleep(1);
	}
*/
	Widget w;
	w.resize(960, 640);
	w.show();

	return a.exec();
}
