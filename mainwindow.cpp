#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stdlib.h>
#include<unistd.h>
#include<QTimer>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //thread = new Thread;
    connect(this, SIGNAL(testsig()), this, SLOT(testslots()) );

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout1()));    //for timeout
    timer->start(3000);
    flag=0;
    //    m_pFileWatcher = new QFileSystemWatcher;
    //    m_pFileWatcher->addPath("/home/iverhan/filetest/aa");
    //    connect( m_pFileWatcher, SIGNAL(fileChanged(QString)), this, SLOT(filechangetest(QString)) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testslots()
{
    qDebug("in slots,%d",flag);
    if(flag==1)
    {
        qDebug("in if,%d",flag);
        //activateWindow();
        showNormal();
        flag = 0;
    }
    else if(flag==0)
    {
        qDebug("in else,%d",flag);
        showMinimized();
        //activateWindow();
        flag = 1;
    }




}

void MainWindow::on_pushButton_clicked()
{
    qDebug("hello");
    //thread->run();

}


void MainWindow::timeout1()
{
    emit testsig();
}

void MainWindow::filechangetest(QString)
{
    qDebug("in emit");
    emit testsig();
}








