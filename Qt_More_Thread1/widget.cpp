#include "widget.h"
#include <QDebug>
#include <windows.h>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	createView();
}

void Widget::createView()
{
	/*��ӽ���*/
	QPushButton *openThreadBtn = new QPushButton(tr("Open Thread"));
	QPushButton *closeThreadBtn = new QPushButton(tr("Close Thread"));
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(openThreadBtn);
	mainLayout->addWidget(closeThreadBtn);
	mainLayout->addStretch();
	connect(openThreadBtn, SIGNAL(clicked(bool)), this, SLOT(openThreadBtnSlot()));
	connect(closeThreadBtn, SIGNAL(clicked(bool)), this, SLOT(closeThreadBtnSlot()));

	/*�̳߳�ʼ��*/
	thread1 = new MyThread;
	connect(thread1, SIGNAL(finished()), this, SLOT(finishedThreadBtnSlot()));
}

void Widget::openThreadBtnSlot()
{
	/*����һ���߳�*/
	thread1->start();
	qDebug() << "Main Thread id��" << QThread::currentThreadId();
}

void Widget::closeThreadBtnSlot()
{
	/*�رն��߳�*/
	thread1->closeThread();
	thread1->wait();
}

void Widget::finishedThreadBtnSlot()
{
	qDebug() << tr("����ź�finished����");
}

Widget::~Widget()
{
}
