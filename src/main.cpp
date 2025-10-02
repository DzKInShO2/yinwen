#include <iostream>
using namespace std;

#include "yw.h"

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
        int text_start = get_text_start(argv, argc);

        // Error bila tidak menemukan text
        if (text_start == 0) {
            clog << "\33[31merror\33[0m: no text is given\n";
            return 0;
        }

        // Set mode sesuai masukan
        text.mode = argv[1][0];

        // Memasukan kalimat dalam
        // variabel text
        text.content = get_text_content(text_start, argv, argc);

        // Iterasi daftar [options] dan Mengeluarkan hasil akhir
        cout << get_processed_text(text, argv, 2, text_start) << endl;
    } else help_page();

    return 0;
}
