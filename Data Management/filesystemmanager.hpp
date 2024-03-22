#ifndef _DATASTRUCTURES_CPP
#define _DATASTRUCTURES_CPP
#include "datastructures.cpp"
#endif

#include <vector>

namespace DataManagement {
    class FilesystemManager;
}

class FilesystemManager {
public:
    struct preset {
        std::string name;
        std::vector<DataStructures::sequenceItem> presetContent;
        preset(std::string name, std::vector<DataStructures::sequenceItem> presetContent) {
            this->name = name;
            this->presetContent = presetContent;
        }
    };

    static std::vector<DataStructures::sequenceItem> parseFile(std::string filename);
    static void generatePresets();
    static std::vector<preset> fetchPresets();
};