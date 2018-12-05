#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <qdebug.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Thread0 = new QThread();
    this->worker0 = new Worker();
    connect(Thread0, SIGNAL(started()), worker0, SLOT(mainFlow()));
    this->worker0->moveToThread(Thread0);
    this->connect(this->ui->pushButton,&QPushButton::clicked,this,&MainWindow::startThread);
    qDebug()<<"Main Thread : "<<this->thread()<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startThread()
{
    if(this->Thread0 != nullptr && this->Thread0->isRunning() == false)
    {
        this->Thread0->start();
    }else{
       qDebug()<<"Already running" <<endl;
    }
}
