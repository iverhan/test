#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stdlib.h>
#include<unistd.h>
#include<QTimer>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void testsig();

private slots:
    void on_pushButton_clicked();
    void testslots();
    void slottimeout();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int flag;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(testsig()), this, SLOT(testslots()) );
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slottimeout()));    //for timeout
    timer->start(3000);
    flag=0;
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
        showNormal();
        flag = 0;
    }
    else if(flag==0)
    {
        qDebug("in else,%d",flag);
        showMinimized();
        flag = 1;
    }
}

void MainWindow::on_pushButton_clicked()
{
    qDebug("hello");
}


void MainWindow::slottimeout()
{
    emit testsig();
}
