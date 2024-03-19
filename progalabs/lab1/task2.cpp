#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i;
    double var1 = -1.1;
    float var2 = -1.5;
    float var3 = 1.9;
    cout << "float -> int" << "\n";
    i = int(var1);
    cout << var1 << "->" << i << "\n";
    i = int(var2);
    cout << var2 << "->" << i << "\n";
    i = int(var3);
    cout << var3 << "->" << i << "\n";
    double var4 = -1.1;
    double var5 = -1.5;
    double var6 = 1.9;
    cout << "double -> int" << "\n";
    i = int(var4);
    cout << var4 << "->" << i << "\n";
    i = int(var5);
    cout << var5 << "->" << i << "\n";
    i = int(var6);
    cout << var6 << "->" << i << "\n";
    bool tvar = true;
    i = int(tvar);
    cout << "bool -> int" << "\n";
    cout << tvar << "->" << i << "\n";
    bool b = 5;
    cout << "bool = 5" << "\n";
    cout << "i = " << i << "\n";
}