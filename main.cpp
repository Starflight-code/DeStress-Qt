#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#ifndef _BASICIMPORTS
#define _BASICIMPORTS
#include <chrono>
#include <cmath>
#include <string>
#include <thread>
#endif

#ifndef _FILESYSTEMMANAGER_CPP
#define _FILESYSTEMMANAGER_CPP
#include "filesystemmanager.cpp"
#endif

int main(int argc, char* argv[]) {
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono;      // nanoseconds, system_clock, seconds
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for(const QString& locale : uiLanguages) {
        const QString baseName = "DeStress-QT_" + QLocale(locale).name();
        if(translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    FilesystemManager::generatePresets();
    MainWindow w;
    w.stashPresetList(FilesystemManager::fetchPresets());
    w.show();
    return a.exec();
}
