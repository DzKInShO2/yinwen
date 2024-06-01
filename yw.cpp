#include <iostream>
using namespace std;

struct Text {
    string content;
    char mode;
};

void reverse_cipher(Text& text)
{
    int n = text.content.size();
    for (int i = 0; i < n / 2; ++i) {
        char c = text.content[i];
        text.content[i] = text.content[n - i - 1];
        text.content[n - i - 1] = c;
    }
}

/*
 * Menampilkan laman bantuan
 */
void help_page()
{
    cout << "Usage: yw [mode] [options]... -i text\n"
         << "Encrypt or decrypt text based on the options given.\n\n"
         << "Mode:\n"
         << "e encrypt text\n"
         << "d decrypt text\n"
         << "Options:\n"
         << " -r reverse cipher\n"
         << " -h show this page\n";
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
            cout << "\33[31merror\33[0m: no text is given\n";
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
                case 'r': reverse_cipher(text);
                    break;
                case 'h': help_page();
                    return 0;
                default:
                    cout << "\33[31merror\33[0m: option "
                         << argv[i] << " is not valid option\n";
                    return 0;
            }
        }

        // Mengeluarkan hasil akhir
        cout << text.content << endl;
    } else help_page();

    return 0;
}
