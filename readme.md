# Basic File Encrypter
This is just a simple program that lets you encrypt and decrypt your files asigning them a key to later descrypt. Made with support for as many platforms as possible and a simple compilation process; there is no 3rd parties stuff (other than premake5), only standard C++ functions.

# How to build/use
Linux:
```sh
git clone https://github.com/almartdev/sfe.git && cd sfe
premake5 gmake2
cd build && make && cd ..
```

Usage (see using -h or --help)
```sh
-f <filename> : file to encrypt/decrypt
-d <key> : decrypt, key is optional
```

# TODO
- keep file name and extension after decrypting