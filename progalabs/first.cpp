#include <iostream>
using namespace std;



int main()
{
    unsigned long int ui;
    long int i;
    float f;
    i = -1;
    ui = i;
    f = ui;
    cout << f << endl;
    f += 1;
    cout << f << endl;

    unsigned long int ui1;
    long int i1;
    double d, e;
    i1 = -1;
    ui1 = i1;
    d = ui1;
    e = ui1;
    cout << d << endl;
    d += 1;
    cout << d << endl;
    if(d == e)
    {
        cout << "ravni" << endl;
    }

    float f1 = 1.0;
    float delta = 1;
    do
    {
        delta/=2;
    }while (f1 + delta != f1);
    cout << "delta for 1.0 --- " << delta << endl;

    float f2 = 10.0;
    float delta2 = 1;
    do
    {
        delta2/=2;
    }while (f2 + delta2 != f2);
    cout << "delta for 1.0 --- " << delta2 << endl;

    return 0;
}