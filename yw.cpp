#include <iostream>
using namespace std;

/*
 * Menampilkan laman bantuan
 */
void help_page()
{
    cout << "Usage: yw [mode] [options]... text\n"
         << "Encrypt or decrypt text based on the options given.\n";
}

int main(int argc, const char* argv[])
{
    if (argc > 2) {

    } else help_page();

    return 0;
}
