#include <string>


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
