#include <iostream>
using namespace std;

#include "yw.h"
#include "cipher.h"

/*
 * Menjalani semua argument dan aplikasikan perubahan ke teks
 */
bool iterate_arguments(Text& text, const char **args, int start, int end)
{
    if (text.mode != 'e' || text.mode != 'd') {
        clog << "\33[31merror\33[0m: option "
            << text.mode << " is not valid mode\n";
        return false;
    }

    if (string(args[end - 1]) != "-i") {
        clog << "\33[31merror\33[0m: option end given is not valid\n";
        return false;
    }

    for (int i = start; i < end - 1; ++i) {
        switch (args[i][1]) {
        case 'a': atbash_cipher(text.content, text.mode);
                  break;
        case 'c': caesar_cipher(text.content, text.mode, stoi(args[++i]));
                  break;
        case 'r': reverse_cipher(text.content, text.mode);
                  break;
        case 'v': vigenere_cipher(text.content, text.mode, args[++i]);
                  break;
        case 'h': help_page();
                  return 0;
        default:
                  clog << "\33[31merror\33[0m: option "
                      << args[i] << " is not valid option\n";
                  return false;
        }
    }

    return true;
}

/*
 * Menampilkan laman bantuan
 */
void help_page()
{
    cout << "Usage: yw [mode] [options]... -i text\n"
            "Encrypt or decrypt text based on the options given.\n\n"
            "Mode:\n"
            "e encrypt text\n"
            "d decrypt text\n"
            "Options:\n"
            " -a Atbash cipher\n"
            " -c [key] Caesar cipher\n"
            " -r reverse cipher\n"
            " -v [word] Vigenere cipher\n"
            " -h show this page\n";
}
