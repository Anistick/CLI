#include <iostream> // Input / Output Stream
#include <string> // String support
#include <fstream> // File stream
#include <Windows.h>

#pragma comment(lib, "urlmon.lib") // Please tell me this works in a MingW64 compiler

using namespace std; // Use namespace STD to prevent std::
int progarg = 0; // Program Argument (anistick.exe)
int firstarg = 1; // Major argument (anistick.exe major) e.g self installs like anistick.exe install
int lastarg = 2; // Minor argument (anistick.exe major minor)
const string typerel = " Release ";
const string ver = "0.3.0";
const string gawname = "GoAnimate Wrapper";
const string binname = "Anistick";
const string wrappero = "Wrapper: Offline";
const string ga4sr = "GoAnimate4Schools Remastered";
const string extvia = " via ";
const string gh = "GitHub";
const string weebly = "Weebly";
const string wix = "Wix";
const string acdn = "Anistick CDN";
ifstream ifile;
LPCTSTR asurl = L"https://github.com/Anistick-Studio/Anistick/archive/refs/heads/main.zip";
LPCTSTR wourl = L"https://github.com/Wrapper-Offline/Wrapper-Offline/archive/refs/heads/main.zip";
LPCTSTR gafurl = L"https://s3.anistick.com/ga4sr.rar/ga4sr.rar";
LPCTSTR gawurl = L"https://github.com/GoAnimate-Wrapper/GoAnimate-Wrapper/archive/refs/heads/main.zip";
LPCTSTR gawfn = L"GoAnimate-Wrapper.zip";
LPCTSTR wofn = L"Wrapper-Offline.zip";
LPCTSTR asfn = L"Anistick.zip";
LPCTSTR gaffn = L"GoAnimate4SchoolsRemastered.rar";
LPCTSTR SUC = L"Success";
DWORD dwz = 0;
wstring fexerr(LPCTSTR fexerrm) {
    wstring xma = wstring(L"File ") + fexerrm + wstring(L" exists. Please delete the file and try again.");
    return xma;
}
wstring wnatderr(LPCTSTR wnatderrm) {
    wstring xma = wstring(L"Was not able to download ") + wnatderrm + wstring(L". Please check your internet connection or any other issues, like a firewall.");
    return xma;
}
wstring DS(LPCTSTR asdcomds) {
    wstring xma = wstring(L"Successfully downloaded ") + asdcomds + wstring(L".");
    return xma;
}
int dwnld(string dwnldmain)
{
    if (dwnldmain == "as") {
        ifile.open(asfn);
        if (ifile) {
            MessageBox(NULL, fexerr(asfn).c_str(), NULL, MB_OK);
            return 1;
        } else {
            cout << "Now downloading " << binname << extvia << gh << "." << endl;
            if (S_OK == URLDownloadToFile(nullptr, (asurl), (asfn), dwz, nullptr)) {
                MessageBox(NULL, DS(asfn).c_str(), SUC, MB_OK);
                return 0;
            }
            else {
                MessageBox(NULL, wnatderr(asfn).c_str(), NULL, MB_OK);
                return firstarg;
            }
            return 0;
        }
    }
    else if (dwnldmain == "wo") {
        ifile.open(wofn);
        if (ifile) {
            MessageBox(NULL, fexerr(asfn).c_str(), NULL, MB_OK);
            return 1;
        }
        else {
            cout << "Now downloading " << wrappero << extvia << gh << "." << endl;
            if (S_OK == URLDownloadToFile(nullptr, (wourl), (wofn), dwz, nullptr)) {
                MessageBox(NULL, DS(wofn).c_str(), SUC, MB_OK);
                return 0;
            }
            else {
                MessageBox(NULL, wnatderr(wofn).c_str(), NULL, MB_OK);
                return firstarg;
            }
            return 0;
        }
    }
    else if (dwnldmain == "ga4sr") {
        ifile.open(gaffn);
        if (ifile) {
            MessageBox(NULL, fexerr(gaffn).c_str(), NULL, MB_OK);
            return 1;
        }
        else {
            cout << "Now downloading " << ga4sr << extvia << acdn << "." << endl;
            if (S_OK == URLDownloadToFile(nullptr, (gafurl), (gaffn), dwz, nullptr)) {
                MessageBox(NULL, DS(gaffn).c_str(), SUC, MB_OK);
                return 0;
            }
            else {
                MessageBox(NULL, wnatderr(gaffn).c_str(), NULL, MB_OK);
                return firstarg;
            }
            return 0;
        }
    }
    else if (dwnldmain == "gaw") {
        ifile.open(gawfn);
        if (ifile) {
            MessageBox(NULL, fexerr(gawfn).c_str(), NULL, MB_OK);
            return 1;
        }
        else {
            cout << "Now downloading " << gawname << extvia << gh << "." << endl;
            if (S_OK == URLDownloadToFile(nullptr, (gawurl), (gawfn), dwz, nullptr)) {
                MessageBox(NULL, DS(gawfn).c_str(), SUC, MB_OK);
                return 0;
            }
            else {
                MessageBox(NULL, wnatderr(gawfn).c_str(), NULL, MB_OK);
                return firstarg;
            }
            return 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i) {
        if (i == firstarg && string(argv[i]) == "install" && argc < 3) {
            dwnld("as");
        } else if (i == lastarg && string(argv[i]) == "anistick" && string(argv[firstarg]) == "install" && argc < 4) {
            dwnld("as");
        } else if (i == lastarg && string(argv[i]) == "wrapper" && string(argv[firstarg]) == "install" && argc < 4) {
            dwnld("wo");
        } else if (i == lastarg && string(argv[i]) == "ga4sr" && string(argv[firstarg]) == "install" && argc < 4) {
            dwnld("ga4sr");
        } else if (i == lastarg && string(argv[i]) == "gawrapper" && string(argv[firstarg]) == "install" && argc < 4) {
            dwnld("gaw");
        }
        else if (i == firstarg && string(argv[i]) == "--help" && argc < 3) {
            cout << "Anistick CLI" << typerel << ver << " help\nanistick install - Installs Anistick.\nanistick install anistick - Installs Anistick.\nanistick install wrapper - Installs Wrapper : Offline.\nanistick install ga4sr - Installs GoAnimate4Schools Remastered.\nanistick install gawrapper - Installs GoAnimate Wrapper.";
        }
    }
    if (argc > 3) {
        cout << "Arguments are too high.";
        return firstarg; // 1 is used for returning errors
    }
    return 0;
}
