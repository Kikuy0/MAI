#include <iostream>

using namespace std;

int main(){
    unsigned char uc;
    uc = 99;
    cout << uc << "\n"; // void
    char c;
    c = 66;
    cout << c << "\n"; // void
    short int si;
    si = 32760;
    si += 10;
    cout << si << "\n"; // overflow
    return 0;
}