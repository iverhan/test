#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QFileSystemWatcher>



//while(1)
//{
//    showNormal();
//    sleep(3);
//    showMinimized();
//    sleep(3);
//}

namespace Ui {
class MainWindow;
}


class Thread : public QThread
{
    Q_OBJECT
public:
    void run()
    {
        while(1)
        {
            emit testsig1();
            sleep(3);
        }

    }
signals:
    void testsig1();

};

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
    void timeout1();
    void filechangetest(QString);

private:
    Ui::MainWindow *ui;
    Thread *thread;
    QTimer *timer;
    int flag;
    QFileSystemWatcher              * m_pFileWatcher;
};

#endif // MAINWINDOW_H
