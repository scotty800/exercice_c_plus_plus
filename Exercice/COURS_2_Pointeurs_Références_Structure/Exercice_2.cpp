#include <iostream>
using namespace std;

int main() 
{
    int a = 7;
    int *p = &a;

    cout << "l'adresse de a : " <<  &a << endl;
    cout << "La valeur de a : " << a << endl;
    cout << "la valeur pointée par p : " << *p << endl;

    *p = 15;

    cout << "l'adresse de a : " <<  &a << endl;
    cout << "La valeur de a : " << a << endl;
    cout << "la valeur pointée par p : " << *p << endl;

    return 0;
}