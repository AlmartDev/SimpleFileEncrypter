#include "encrypter.h"

void Encrypter::encrypt() {
    std::cout << "Encrypting " << this->path << std::endl;

    std::cout << "Select key or type 0 for a random key: ";
    std::cin >> key;

    if (key == 0) {
        key = rand() % 9999;    // Random key
        std::cout << "Random key (dont forget it!): " << key << std::endl;
    }

    std::fstream fin, fout;

    fin.open(path, std::fstream::in);
    fout.open(path + ".sfe", std::fstream::out); 

    while (fin >> std::noskipws >> c) {

        if (c == '\n') {
            fout << c;
            continue;
        }

        int temp = (c + key);
        fout << (char)temp;
    }

    // Delete the original file
    remove(path.c_str());
 
    // Closing both files
    fin.close();
    fout.close();
}

void Encrypter::decrypt() {
    std::cout << "Decrypting " << this->path << std::endl;

    if (key == 0) {
        std::cout << "Enter key: ";
        std::cin >> key;
    }

    // TODO: key validation?

    std::fstream fin;
    std::fstream fout;

    std::string name = path.substr(0, path.find_last_of("."));
    std::string extension = path.substr(path.find_last_of("."));

    fin.open(path, std::fstream::in);
    fout.open(path.substr(0, path.find_last_of(".")), std::fstream::out);
 
    while (fin >> std::noskipws >> c) { 
        if (c == '\n') {
            fout << c;
            continue;
        }

        int temp = (c - key);
        fout << (char)temp;
    }

    // debug
    std::cout << "\nName: " << name << std::endl;
    std::cout << "Extension: " << extension << "\n" << std::endl;

    // if (!extension.empty() && !name.empty()) {
    //     std::string originalName = name + "." + extension;
    //     fout.close();
    //     rename("decrypted", originalName.c_str());
    // }

    // Delete the original file
    remove(path.c_str());
 
    fin.close();
    fout.close();
}

Encrypter::Encrypter(bool _decrypt, const std::string &_path, int _key) {
    this->path = _path;
    this->key = _key;
    this->toDecrypt = _decrypt;

    if (this->toDecrypt) 
        decrypt();
    else 
        encrypt();
}

Encrypter::~Encrypter() {
    std::cout << "Done" << std::endl;   
}