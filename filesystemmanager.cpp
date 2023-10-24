#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifndef _CONSTANTS_CPP
#define _CONSTANTS_CPP
#include "constants.cpp"
#endif

#ifndef _DATASTRUCTURES_CPP
#define _DATASTRUCTURES_CPP
#include "datastructures.cpp"
#endif

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

    static std::vector<DataStructures::sequenceItem> parseFile(std::string filename) {
        std::vector<DataStructures::sequenceItem> outputVector;
        std::ifstream file (filename);
        std::string line;
        std::string text;
        int i = 0;
        while (file) {
            std::getline(file, line);
            switch (i % 2) {
            case 0: // Text Line
                text = line;
                break;
            case 1: // Wait Time Line
                try {
                    outputVector.push_back(DataStructures::sequenceItem(text, std::stoi(line)));
                } catch (std::exception) {
                    return std::vector<DataStructures::sequenceItem>();
                }
                break;
            }
            i++;
        }
        return outputVector;
    }

    static void generatePresets() {
        Constants c;
        std::string currentPath = std::filesystem::current_path().string();
        std::filesystem::create_directory(currentPath + c.assetFolderAppend);
        //std::cout << currentPath + c.assetFolderAppend + "/4-4-4-breathing.txt";
        std::ofstream fourBreathing(currentPath + c.assetFolderAppend + "/4-4-4-breathing.txt");
        fourBreathing << c.fourfourfourbreathing;
        fourBreathing.flush();
        fourBreathing.close();
    }

    static std::vector<preset> fetchPresets() {
        std::vector<preset> presets;
        Constants c;
        std::string currentPath = std::filesystem::current_path().string();
        std::vector<std::string> files;
        for (const auto & entry : std::filesystem::directory_iterator(currentPath + c.assetFolderAppend)) {
            //std::cout << entry.path() << std::endl;
            files.push_back(entry.path());
        }
        for (int i = 0; i < files.size(); i++) {
            std::string name = files[i];
            name.replace(0, currentPath.size() + c.assetFolderAppend.size() + 1,"");
            int positionOfExtension = name.find(".");
            name.replace(positionOfExtension,name.size() - positionOfExtension, "");
            presets.push_back(preset(name, parseFile(files[i])));
        }
        return presets;
    }

};
