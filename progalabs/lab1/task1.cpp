#include <iostream>
using namespace std;
int main(){
    int sz;
    short int si;// 2 байта
    int i;
    long int li;
    long long int lli;
    float f;
    //long float lf;
    double d;
    long double ld;
    bool b;
    char c;
    wchar_t wc;
    sz = sizeof(si);
    cout << "Size of short int: " << sz << " byte" << endl;
    sz = sizeof(i);
    cout << "Size of int: " << sz << " byte" << endl;
    sz = sizeof(li);
    cout << "Size of long int: " << sz << " byte" << endl;
    sz = sizeof(lli);
    cout << "Size of long long int: " << sz << " byte" << endl;
    sz = sizeof(f);
    cout << "Size of float: " << sz << " byte" << endl;
    sz = sizeof(d);
    cout << "Size of double: " << sz << " byte" << endl;
    sz = sizeof(ld);
    cout << "Size of long double: " << sz << " byte" << endl;
    sz = sizeof(b);
    cout << "Size of bool: " << sz << " byte" << endl;
    sz = sizeof(c);
    cout << "Size of char: " << sz << " byte" << endl;
    sz = sizeof(wc);
    cout << "Size of wchar_t: " << sz << " byte" << endl;
    return 0;
}