#include <iostream>
using namespace std;

int main() {
    int notes[5] = {12, 15, 14, 10, 13};
    int somme = 0, i;
    double moyenne;
    int maxNote = notes[0];

    for (i = 0; i < 5; i++)
    {
        somme += notes[i];
        if (notes[i] > maxNote) {
            maxNote = notes[i];
        }
    }
    moyenne = somme / 5.0;
    cout << "La moyenne est " << moyenne << endl;
    cout << "La note maximale est " << maxNote << endl;
}