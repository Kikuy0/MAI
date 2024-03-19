#include <iostream>
#include <cmath>


using namespace std;


int task1d1(int x){
    int degree = 1;
    if (x == 1){
        return 0;
    }
    if (x == 0){
        return -1;
    }
    while (x != 1){
        if (x % 2 != 0 ){
            return -1;
        }
        else{
            x /= 2;
            degree += 1;
        }
    }
    return degree - 1;
}

int task1d2(int x){
    int degree = 0, t = 1;
    if (x == 1){
        return 0;
    }
    while (t * 2 <= x){
        t *= 2;
        degree += 1;
    }
    if (t != x || x == 0){
        return -1;
    }
    else{
        return degree;
    }
}

int task2(int n){
    double summ = 0;
    for (int i = 0; i < n; i++){
        summ += (1/pow(2, i));
    }
    return summ;
}


int main(){
    int k, n, x;
    cout << "Choose task(1, 2, 3): \n";
    cin >> k;
    switch (k) {
        case 1:
            cout << "Enter x:\n";
            cin >> x;
            if (task1d1(x) != -1)cout << task1d1(x) << "\n";
            else cout << "Не степень двойки." << "\n";
            break;
        case 2:
            cout << "Enter x: \n";
            cin >> x;
            if (task1d2(x) != -1)cout << task1d2(x) << "\n";
            else cout << "Не степень двойки." << "\n";
            break;
        case 3:
            cout << "Enter n: ";
            cin >> n;
            cout << task2(n) << "\n";
            break;                   
    }   
    return 0;
}