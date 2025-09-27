#include <iostream>
using namespace std;

#include "cipher.h"

struct Text {
    char mode;
    string content;
};

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

int main(int argc, const char* argv[])
{
    Text text;
    if (argc > 1) {
        // Tampilkan laman bantuan
        // dan selesai
        if (string(argv[1]) == "-h") {
            help_page();
            return 0;
        }

        // Mencari awal dari kalimat
        int text_start = 0;
        for (int i = 2; i < argc; ++i) {
            if (string(argv[i]) == "-i") {
                text_start = i + 1;
                break;
            }
        }

        // Error bila tidak menemukan text
        if (text_start == 0) {
            clog << "\33[31merror\33[0m: no text is given\n";
            return 0;
        }

        // Error jika mode tidak disediakan
        // atau salah
        if (argv[1][0] != 'd' && argv[1][0] != 'e') {
            clog << "\33[31merror\33[0m: no mode is specified\n";
            return 0;
        }

        // Set mode sesuai masukan
        text.mode = argv[1][0];

        // Memasukan kalimat dalam
        // variabel text
        for (int i = text_start; i < argc; ++i) {
            text.content += argv[i];
            if (i != argc - 1) text.content += " ";
        }

        // Iterasi daftar [options]
        for (int i = 2; i < text_start - 1; ++i) {
            switch (argv[i][1]) {
                case 'a': atbash_cipher(text.content, text.mode);
                    break;
                case 'c': caesar_cipher(text.content, text.mode, stoi(argv[++i]));
                    break;
                case 'r': reverse_cipher(text.content, text.mode);
                    break;
                case 'v': vigenere_cipher(text.content, text.mode, argv[++i]);
                    break;
                case 'h': help_page();
                    return 0;
                default:
                    clog << "\33[31merror\33[0m: option "
                         << argv[i] << " is not valid option\n";
                    return 0;
            }
        }

        // Mengeluarkan hasil akhir
        cout << text.content << endl;
    } else help_page();

    return 0;
}
