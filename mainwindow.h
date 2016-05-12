#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "work.h"
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    
private slots:
    void on_btn_Click_clicked();
    void On_change(QString);
private:
    Ui::MainWindow *ui;
    Work *mwork;
    QThread *mthread;

};

#endif // MAINWINDOW_H
