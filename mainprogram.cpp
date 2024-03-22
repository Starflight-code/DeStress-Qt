#include "mainprogram.h"
#include "ui_mainprogram.h"

// #ifndef _IOSTREAM
// #define _IOSTREAM
// #include <iostream>
// #endif

#ifndef _BASICIMPORTS
#define _BASICIMPORTS
#include <chrono>
#include <cmath>
#include <string>
#include <thread>
#endif

#ifndef _DATASTRUCTURES_CPP
#define _DATASTRUCTURES_CPP
#include "datastructures.cpp"
#endif

MainProgram::MainProgram(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainProgram) {
  ui->setupUi(this);
}
void MainProgram::start(std::vector<DataStructures::sequenceItem> list,
                        int forTimeInMinutes) {
  auto animation = [](Ui::MainProgram *window, int time_in_seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    int updateInterval_ms = 10;
    int step = updateInterval_ms / time_in_seconds;
    // std::cout << "Step: ";
    // std::cout << step;
    bool done = false;
    int i = 0;
    while (!done) {
      i += step;
      window->progressBar->setValue(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(updateInterval_ms));
      if (i >= 1000) {
        done = true;
      }
    }
  };
  this->show();
  int totalSeconds = 0;
  for (int i = 0; i < list.size(); i++) {
    totalSeconds += list[i].timeInSeconds;
  }
  int numberOfCycles = std::round(float(forTimeInMinutes) * 60 / totalSeconds);
  for (int i = 0; i < numberOfCycles; i++) {
    for (int j = 0; j < list.size(); j++) {
      // std::cout << "Ran ";
      // std::cout << (i + 1);
      // std::cout << " times\n";
      ui->label->setText(QString::fromStdString(list[j].label));
      animation(ui, list[j].timeInSeconds);
    }
  }
  this->hide();
}

MainProgram::~MainProgram() { delete ui; }
