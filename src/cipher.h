#pragma once

#include <string>

void atbash_cipher(std::string& content, char mode);
void caesar_cipher(std::string& content, char mode, int key);
void reverse_cipher(std::string& content, char mode);
void vigenere_cipher(std::string& content, char mode, const std::string& key);
