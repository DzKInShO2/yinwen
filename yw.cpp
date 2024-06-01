#include <iostream>
using namespace std;

/*
 * Menampilkan laman bantuan
 */
void help_page()
{
    cout << "Usage: yw [mode] [options]... text\n"
         << "Encrypt or decrypt text based on the options given.\n\n"
         << "Mode:\n"
         << "e encrypt text\n"
         << "d decrypt text\n"
         << "Options:\n"
         << " -h show this page\n";
}

int main(int argc, const char* argv[])
{
    string text;
    char mode;
    if (argc > 1) {
        // Tampilkan laman bantuan
        // dan selesai
        if (string(argv[1]) == "-h") {
            help_page();
            return 0;
        }

        if (argc < 3) {
            cout << "\33[31merror\33[0m: no text is given\n";
            return 0;
        }

        // Set mode sesuai masukan
        mode = argv[1][0];
        // Iterasi daftar [options]
        for (int i = 2; i < argc - 1; ++i) {
            switch (argv[i][1]) {
                // Laman bantuan
                case 'h': help_page();
                break;
            }
        }
    } else help_page();

    return 0;
}
