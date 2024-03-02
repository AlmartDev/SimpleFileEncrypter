#include "encrypter.h"

void Encrypter::encrypt() {
    std::cout << "Encrypting " << this->filename << std::endl;

    std::cout << "Select key or type 0 for a random key: ";
    std::cin >> key;

    if (key == 0) {
        key = rand() % 9999;    // Random key
        std::cout << "Random key (dont forget it!): " << key << std::endl;
    }

    std::fstream fin, fout;

    fin.open(filename, std::fstream::in);
    fout.open("encrypt.sfe", std::fstream::out);    // using .sfe extension for encrypted file (Simple File Encryptor)

    while (fin >> std::noskipws >> c) {
        int temp = (c + key);
 
        // Write temp as char in
        // output file
        fout << (char)temp;
    }

    // Delete the original file
    remove(filename.c_str());
 
    // Closing both files
    fin.close();
    fout.close();
}

void Encrypter::decrypt() {
    std::cout << "Decrypting " << this->filename << std::endl;

    if (key == 0) {
        std::cout << "Enter key: ";
        std::cin >> key;
    }

    std::fstream fin;
    std::fstream fout;

    fin.open(filename, std::fstream::in);
    fout.open("decrypt.txt", std::fstream::out);
 
    while (fin >> std::noskipws >> c) {
 
        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }

    // Delete the original file
    remove(filename.c_str());
 
    fin.close();
    fout.close();
}

Encrypter::Encrypter(bool _decrypt, const std::string &_filename, int _key) {
    this->filename = _filename;
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