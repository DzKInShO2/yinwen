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
Usage: yw [mode] [options]... -i text
Encrypt or decrypt text based on the options given.

Mode:
e encrypt text
d decrypt text
Options:
 -a Atbash cipher
 -c [key] Caesar cipher
 -r reverse cipher
 -v [word] Vigenere cipher
 -h show this page

$ ./yw e -a -i Hello, World! // Cipher the text using Atbash cipher
Svool, Dliow!

$ ./yw d -a -i Svool, Dliow! // Decipher Atbash ciphered text
Hello, World!
```
