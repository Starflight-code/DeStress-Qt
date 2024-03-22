#ifndef _BASICIMPORTS
#define _BASICIMPORTS
#include <string>
#include <chrono>
#include <thread>
#include <cmath>
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

    DataStructures()
    {

    }


};
