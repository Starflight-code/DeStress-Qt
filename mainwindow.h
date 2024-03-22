#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef _FILESYSTEMMANAGER_CPP
#define _FILESYSTEMMANAGER_CPP
#include "filesystemmanager.cpp"
#endif

#include "mainprogram.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void stashPresetList(std::vector<FilesystemManager::preset>);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
    std::vector<FilesystemManager::preset> presets;
    MainProgram program;
};
#endif // MAINWINDOW_H
