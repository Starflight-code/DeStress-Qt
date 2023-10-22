#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mainprogram.h"

#ifndef _IOSTREAM
#define _IOSTREAM
#include <iostream>
#endif

#ifndef _BASICIMPORTS
#define _BASICIMPORTS
#include <thread>
#include <chrono>
#include <string>
#endif

#include <math.h>
#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>

#ifndef _DATASTRUCTURES_CPP
#define _DATASTRUCTURES_CPP
#include "datastructures.cpp"
#endif


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

void MainWindow::stashInstanceOfProgram() {
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->currentIndex();
    std::vector<DataStructures::sequenceItem> sequence;
    sequence.push_back(DataStructures::sequenceItem("Test", 5));
    this->hide();
    std::cout << "Starting Program";
    auto threaded = [this](std::vector<DataStructures::sequenceItem> x) {
        this->program.start(x);
        this->show();
    };
    std::thread thread_object(threaded, sequence);
    thread_object.detach();
    //program.start(sequence);
    //this->show();

}
