#include "mainprogram.h"
#include "ui_mainprogram.h"
#include <chrono>
#include <thread>
#include <string>

#ifndef _DATASTRUCTURES_CPP
#define _DATASTRUCTURES_CPP
#include "datastructures.cpp"
#endif

MainProgram::MainProgram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainProgram)
{
    ui->setupUi(this);
}

void MainProgram::start(std::vector<DataStructures::sequenceItem> list) {
    auto animation = [](Ui::MainProgram *window, int time_in_seconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        int updateInterval_ms = 10;
        int step =  updateInterval_ms / time_in_seconds;
        bool done = false;
        int i = 0;
        while(!done) {
            i += step;
            window->progressBar->setValue(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(updateInterval_ms));
            if (i > 1000) {
                done = true;
            }
        }
    };
    for (int i = 0; i < list.size(); i++) {
        ui->label->setText(QString::fromStdString(list[i].label));
        animation(ui, list[i].timeInSeconds);
    }
}

MainProgram::~MainProgram()
{
    delete ui;
}

