#include <iostream>
using namespace std;

#include "yw.h"
#include "cipher.h"
#include <cstdlib>

int get_text_start(const char **argv, int argc)
{
    int text_start = 0;
    for (int i = 2; i < argc; ++i) {
        if (string(argv[i]) == "-i") {
            text_start = i + 1;
            break;
        }
    }

    return text_start;
}

std::string get_text_content(int text_start, const char **argv, int argc)
{
    std::string content;
    for (int i = text_start; i < argc; ++i) {
        content += argv[i];
        if (i != argc - 1) content += " ";
    }

    return content;
}

/*
 * Menjalani semua argument dan aplikasikan perubahan ke teks */
std::string get_processed_text(Text& text, const char **args, int start, int end)
{
    // Error jika mode tidak disediakan
    // atau salah
    if (text.mode != 'd' && text.mode != 'e') {
        clog << "\33[31merror\33[0m: mode " 
            << text.mode << " is not valid\n";
        exit(0);
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
                  return "";
        }
    }

    return text.content;
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
