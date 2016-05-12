#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mwork=new Work();
    mthread=new QThread();
    mwork->moveToThread(mthread);
    connect(mwork,SIGNAL(requestWork()),mthread,SLOT(start()));//khi mwork gap tin hieu requestwork thi mthread chay start
    connect(mthread,SIGNAL(started()),mwork,SLOT(doWork()));/*khi mthread da chay started thi mwork thuc hien dowork.
    Do trong dowork co kich tin hieu emit Workrequest(QString). nen khi dowork chay thi workrequest cung dc thuc hien.
    */
    connect(mwork,SIGNAL(Workrequest(QString)),this,SLOT(On_change(QString)));/*workrequest chay thi tai minwindown chay ham On_change*/
    ui->plt_1->insertPlainText("active thread");
    ui->plt_1->insertPlainText("\n");
    ui->plt_1->moveCursor(QTextCursor::End);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::On_change(QString m)
{
    ui->plt_1->insertPlainText(m);
    ui->plt_1->insertPlainText("\n");
    ui->plt_1->moveCursor(QTextCursor::End);
}

void MainWindow::on_btn_Click_clicked()
{
    mwork->requestWork();
}
