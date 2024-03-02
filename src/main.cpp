// Basic File Encryption/Decryption Program
#include <iostream>

#include "inputParser.h"
#include "encrypter.h"

int main(int argc, char* argv[]) {
    InputParser input(argc, argv);

    bool decrypt = input.cmdOptionExists("-d");
    int key = 0;
    if (decrypt) {
        try {
            key = std::stoi(input.getCmdOption("-d"));
        } catch (std::invalid_argument &e) {
            key = 0;
        }
    }

    if(input.cmdOptionExists("-h") || input.cmdOptionExists("--help")){
        std::cout << "Usage: " << argv[0] << " -f <filename>" << std::endl;
        std::cout << "-d <key> : decrypt (key is optional)" << std::endl;
        return 0;
    }

    const std::string &filename = input.getCmdOption("-f");
    if (!filename.empty()){
        std::cout << "Filename: " << filename << std::endl;
    } else {
        std::cerr << "No filename specified" << std::endl;
        return 1;
    }

    Encrypter encrypter(decrypt, filename, key);

    return 0;
}
