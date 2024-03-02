#include <iostream>
#include <string>

#include <fstream>
#include <strstream>

class Encrypter{
    public:
        Encrypter(bool _decrypt, const std::string &_path, int _key = 0);
        ~Encrypter();
    private:
        int key;
        char c;

        void encrypt();
        void decrypt();

        std::string path;
        bool toDecrypt;
};