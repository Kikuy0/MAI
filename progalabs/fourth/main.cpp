#include <iostream>
#include "funcs.h"


using namespace std;

int main(){
    int k, a, b, c, d, n, ans;
    cout << "Choose: \n1.Odd\n2.Square\n3.length\n";
    cin >> k;
    switch (k) {
        case 1:
            cout << "Enter n: ";
            cin >> n;
            cout << "Enter numbers: ";
            ans = odd(n);
            cout << "Number of odds: "  << ans << "\n";
            break;
        case 2:
            cout << "Enter coords(a ,b,c,d): \n";
            cin >> a >> b >> c >> d;
            cout << "Square: " << square(a, b, c, d) << "\n";
            break;
        case 3:
            cout << "Enter coords(a, b, c, d): \n";
            cin >> a >> b >> c >> d;
            cout << "Length: " << length(a, b, c, d) << "\n";
            break;
    }
}