#include <iostream>
using namespace std;

int triple(int &n)
{
    return n = n * 3;
}

int main()
{
    int a = 5;
    cout << "Avant appel de la fonction, a = " << a << endl;
    triple(a);
    cout << "Après appel de la fonction, a = " << a << endl;

    return 0;

}