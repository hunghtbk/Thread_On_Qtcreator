#ifndef WORK_H
#define WORK_H

#include <QObject>

class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(QObject *parent = 0);
    
signals:
    void requestWork();
    void Workrequest(QString);
public slots:
    void doWork();
};

#endif // WORK_H
