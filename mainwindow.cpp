#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <thread>
#include <chrono>
#include <math.h>
#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    auto animation = [](Ui::MainWindow *window, int time_in_seconds) {
        /*std::this_thread::sleep_for(std::chrono::milliseconds(100));
        int updateInterval_ms = 10;
        int step =  updateInterval_ms / time_in_seconds;
        bool done = false;
        int i = 0;
        while(!done) {
            i += step;
            window->progressBar->setValue(i);
            window->progressBar_2->setValue(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(updateInterval_ms));
            if (i > 1000) {
                done = true;
            }
        }*/
    };
    //using namespace std::this_thread; // sleep_for, sleep_until
    //using namespace std::chrono; // nanoseconds, system_clock, seconds
    ui->setupUi(this);
    ui->listWidget->addItem("Test");
    ui->listWidget->addItem("Test2");
    ui->listWidget->addItem("Test3");
    //std::thread thread_object(animation, ui, 10);
    //thread_object.detach();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->currentIndex();
}

