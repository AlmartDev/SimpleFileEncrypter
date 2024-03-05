// Brute force decrypter for the simple file encrypter (sfe)

#include "decrypter.h"

bool askUser(const std::string &decryptedStart) {
    std::cout << "Is this the start of the file? (y/n or enter)" << std::endl;
    std::cout << decryptedStart << std::endl;

    char answer;
    std::cin >> answer;

    // clear screen
    std::cout << "\033[2J\033[1;1H";

    if (answer == 'y') {
        return true;
    } else {
        return false;
    }
}

Decrypter::Decrypter(const std::string &file) {
    std::cout << "Brute force decrypting " << file << std::endl;
    std::cout << "This may take a while... (even years or never!)" << std::endl;
    std::cout << "Press Ctrl+C to stop" << std::endl;

    std::string name = file.substr(0, file.find_last_of("."));
    std::string extension = file.substr(file.find_first_of("."));

    std::string newFile = name + "_decrypted" + extension;

    std::fstream fin;
    std::fstream fout;

    fin.open(file, std::fstream::in);
    fout.open(newFile, std::fstream::out);

    int key = 1; // key cant be 0

    while(true) {
        // Lets try something
        // If decrypting with this ket the first character is either a letter or a number
        // decrypt all of the file with this key and ask the user if the result is correct
        // if it is, then we are done
        // if the character is a \n, go to next character

        std::cout << "Trying key " << key << std::endl;

        char firstChar;
        bool isStartDecrypted = false;

        while (true) {
            fin.get(firstChar);
            char decryptedChar = firstChar - key;

            if (isalpha(decryptedChar) || isdigit(decryptedChar)) {
                // get first ten encrypted characters
                std::string decryptedStart;
                fin.seekg(0, std::ios::beg);

                for (int i = 0; i < 10; i++) {
                    char c;
                    fin.get(c);
                    c = c - key;
                    decryptedStart += c;
                }

                if (askUser(decryptedStart)) {
                    // decrypt the whole file and write it to the new file
                    char c;
                    fin.seekg(0, std::ios::beg);
                    while (fin >> std::noskipws >> c) {
                        if (c == '\n') {
                            fout << c;
                            continue;
                        }

                        int temp = (c - key);
                        fout << (char)temp;
                    }
                    std::cout << "Decrypted file written to " << newFile << std::endl;
                    std::cout << "Key: " << key << std::endl;
                    return;
                }

            } else if (decryptedChar == '\n' || decryptedChar == ' ') {
                // Go to next character
                key++;
                continue;
            }

            // Clear screen
            std::cout << "\033[2J\033[1;1H";

            // Try next key
            key++;
        }        
    }

    fin.close();
    fout.close();
}

Decrypter::~Decrypter() {
    std::cout << "Done!" << std::endl;
}