#include "worker.h"
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::mainFlow()
{

    qDebug()<<"Auxilary Thread : "<<this->thread()<<endl;
    for(int i=0; i<1000;i++)
    {
       qDebug()<<"i : "<<i<<endl;
    }
    qDebug()<<"Auxilary Thread : "<<this->thread()<<endl;

}
