#include <iostream>
#include <cmath>

using namespace std;


int square(int a, int b, int c, int d){
    return abs(a - c) * abs(b - d);
}

int odd(int n){
    int count = 0, x;
    for (int i = 0; i < n; i ++){
        cin >> x;
        if (x % 2 != 0) count++;
    }
    return count;
}

double length(int a, int b, int c, int d){
    return pow(((pow((a - c), 2) + pow((b - d), 2))), 0.5);
}