# Basic File Encrypter
The Basic File Encrypter is a straightforward program designed to encrypt and decrypt files by assigning them a key for later decryption. It is developed with support for multiple platforms and boasts a simple compilation process, utilizing only standard C++ functions without any third-party dependencies other than premake5.
# How to Build and Use
Linux:
```sh
git clone https://github.com/AlmartDev/sfe.git && cd sfe
premake5 gmake2 # or gmake if you want
cd build && make && cd ..
```
Your build should be found in ```bin/Debug/Encrypter```, you can also use ```Release``` or ```Dist``` build configs.

Usage:
After building the program, you can use it with the following command line options:

    -f <filename>: Specify the file to encrypt or decrypt.
    -d <key>: Decrypt the file, where the key is optional.

For more detailed instructions, refer to the help section by using -h or --help.
# TODO
Enhancements planned for future updates include:
- Adding the capability to encrypt entire directories.

# Encrypted file
There is a encrypted file, can you unencrypt it without the key?
<details>
  <summary>File key</summary>
  Yes, the key is 1234!
</details>
