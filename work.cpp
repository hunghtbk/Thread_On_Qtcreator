#include "work.h"

Work::Work(QObject *parent) :
    QObject(parent)
{
}


void Work::doWork()
{
    for(int i=0;i<1000;i++){
        emit Workrequest(QString::number(i));
        sleep(1);
    }
}
