#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <QMainWindow>

#ifndef _DATASTRUCTURES_CPP
#define _DATASTRUCTURES_CPP
#include "../Data Management/datastructures.cpp"
#endif

namespace Ui {
    class MainProgram;
}

class MainProgram : public QMainWindow {
    Q_OBJECT

public:
    explicit MainProgram(QWidget* parent = nullptr);
    ~MainProgram();
    void start(std::vector<DataStructures::sequenceItem>, int);

private:
    Ui::MainProgram* ui;
};

#endif // MAINPROGRAM_H
