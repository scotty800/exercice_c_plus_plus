#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int i;
    double racine;

    for (i = 1; i <= 5; i++)
    {
        racine = pow(i, 2);
        cout << "Le carré de " << i << " est " << racine << endl;
    }
}
