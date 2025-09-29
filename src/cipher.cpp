#include "cipher.h"


/*
 * Implementasi Atbash cipher
 */
void atbash_cipher(std::string& content, char mode)
{
    for (int i = 0; i < content.size(); ++i) {
        if (content[i] == ' ')
            continue;

        if (content[i] >= 'a' && content[i] <= 'z') {
            if (content[i] - '`' > '{' - content[i]) {
                content[i] = '{' - (content[i] - '`');
            } else if (content[i] - '`' < '{' - content[i]){
                content[i] = '`' + ('{' - content[i]);
            }
        } else if (content[i] >= 'A' && content[i] <= 'Z') {
            if (content[i] - '@' > '[' - content[i]) {
                content[i] = '[' - (content[i] - '@');
            } else if (content[i] - '@' < '[' - content[i]) {
                content[i] = '@' + ('[' - content[i]);
            }
        }
    }
}

/*
 * Implementasi Caesar cipher
 */
void caesar_cipher(std::string& content, char mode, int key)
{
    for (int i = 0; i < content.size(); ++i) {
        if (content[i] == ' ')
            continue;

        char c = content[i];
        if (mode == 'e') c += key;
        else if (mode == 'd') c -= key;

        if (content[i] >= 'a' && content[i] <= 'z') {
            if (mode == 'e' && c - 'z' > 0)
                c = '`' + (c - 'z');
            else if (mode == 'd' && c < 'a')
                c = '{' - ('a' - c);
        } else if (content[i] >= 'A' && content[i] <= 'Z') {
            if (mode == 'e' && c - 'Z' > 0)
                c = '@' + (c - 'Z');
            else if (mode == 'd' && c < 'A')
                c = '[' - ('A' - c);
        }
        content[i] = c;
    }
}

/*
 * Implementasi reverse cipher
 */
void reverse_cipher(std::string& content, char mode)
{
    const int& n = content.size();
    for (int i = 0; i < n / 2; ++i) {
        char c = content[i];
        content[i] = content[n - i - 1];
        content[n - i - 1] = c;
    }
}

/*
 * Implementasi Vigenere ciper
 * */
void vigenere_cipher(std::string& content, char mode, const std::string& key)
{
    std::string& s = content;
    for (int i = 0, j = 0; i < content.size(); ++i) {
        if (s[i] == ' '|| 
            !((s[i] < '[' && s[i] > '@') || s[i] <'{' && s[i] > '`')) {
            j++;
            continue;
        }
        char k = key[(i - j) % key.size()];
        if (k < '[' && k > '@')
            k = k - 'A';
        else if (k < '{' && k > '`')
            k = k - 'a';

        if (s[i] < '[' && s[i] > '@') {
            int c = 0;
            if (mode == 'e') {
                c = (int)(s[i] - 'A') + k;
                if (c >= 26) c -= 26;
            }
            else { 
                c = (int)(s[i] - 'A') - k;
                if (c < 0) c += 26;
            }

            s[i] = c + 'A';
        } else if (s[i] < '{' && s[i] > '`') {
            int c = 0;
            if (mode == 'e') {
                c = (int)(s[i] - 'a') + k;
                if (c >= 26) c-= 26;
            } else {
                c = (int)(s[i] - 'a') - k;
                if (c < 0) c += 26;
            }

            s[i] = c + 'a';
        }
    }
}

