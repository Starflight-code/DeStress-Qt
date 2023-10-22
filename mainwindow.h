#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainprogram.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void stashInstanceOfProgram();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MainProgram program;
};
#endif // MAINWINDOW_H
