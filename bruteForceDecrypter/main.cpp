#include "decrypter.h"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    }

    Decrypter decrypter(argv[1]);

    return 0;
}
