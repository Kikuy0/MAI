#include <iostream>
#include <cmath>


using namespace std;

const int x1 = -10;
const int x2 = -8;
const int x3 = -6;
const int x4 = 2;
const int x5 = 6;
const int x6 = 8;

int zadani1(){
    double x, y;
    cout << "Введите координаты точки x: ";
    cin >> x;
    if (x1 <= x && x <= x3) y=pow(4 - (x+8)*(x+8), 0.5)-2;
    if (x3 < x && x <= x4) y = 0.5 * x + 1;
    if (x4 < x && x <= x5 ) y = 0;
    if (x5 < x && x <= x6) y = (x - 6) * (x - 6);
    cout << "x = " << x << '\t' << "y = " << y << '\n';
    return 0;
}

int zadani2(){
    double x, y, r;
    cout << "Введите координаты точки x, y и R: ";
    cin >> x >> y >> r;
    if (x >= 0) {
        if((x*x + y*y) <= r*r){
            cout << "popal" << "\n";
            return 0;
        }
    }
    else{
        if (((x<=y) && (y>= -r)) || ((y >= -x) && (y <= r))){
            cout << "popal" << "\n";
            return 0;
        }
    }
    cout << "nepopal" << "\n";
    return 0;
}


int main(){
    zadani1();
    zadani2();
    return 0;
}