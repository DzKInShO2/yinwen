# YinWen(隐文): Basic CLI Text Encryption and Decription Tool

This project aims to create a simple cipher cli (command line interface) tool that could cipher and decipher text.

## Requirements
- g++

## Quick Start
```
$ g++ yw.cpp -o yw
$ ./yw
```

## Example of Use
```
$ ./yw     // Show help screen
$ ./yw -h  //
$ ./yw e -a -i Hello, World! // Cipher the text using Atbash cipher
$ ./yw d -v lemon -i Lxfopv Ef Rnhr 12 // Decipher Vigenere ciphered text
```
