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
    string text = "";
    if (argc > 2) {
        // Tampilkan laman bantuan
        // dan selesai
        if (string(argv[2]) == "-h") {
            help_page();
            return 0;
        }

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
