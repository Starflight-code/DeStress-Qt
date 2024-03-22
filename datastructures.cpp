#ifndef _BASICIMPORTS
#define _BASICIMPORTS
#include <chrono>
#include <cmath>
#include <string>
#include <thread>
#endif

class DataStructures {
public:
    struct sequenceItem {
        int timeInSeconds;
        std::string label;
        sequenceItem(std::string label, int timeInSeconds) {
            this->label = label;
            this->timeInSeconds = timeInSeconds;
        }
    };

    DataStructures() {
    }
};
