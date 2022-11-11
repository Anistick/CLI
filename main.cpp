#include <iostream> // Input / Output Stream
#include <string> // String support
using namespace std; // Use namespace STD to prevent std::
int progarg = 0; // Program Argument (anistick.exe)
int firstarg = 1; // Major argument (anistick.exe major) e.g self installs like anistick.exe install
int lastarg = 2; // Minor argument (anistick.exe major minor)
string binname = "Anistick";
string ghvia = " via GitHub";
string extvia = "via external source";
int main(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i) {
        if (i == firstarg && string(argv[i]) == "install" && argc < 3) {
            cout << "Now installing " << binname << ghvia << "." << endl;
        }
    }
    if (argc > 3) {
        cout << "Arguments are too high.";
        return firstarg;
    }
    return 0;
}
