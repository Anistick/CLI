#include <iostream>
#include <string>
using namespace std;
int progarg = 0;
int firstarg = 1;
int lastarg = 2;
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
    if (argc > 2) {
        return -1;
    }
    return 0;
}
