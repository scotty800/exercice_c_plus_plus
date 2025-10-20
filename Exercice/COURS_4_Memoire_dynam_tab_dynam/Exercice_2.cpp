#include <iostream>
using namespace std;

int main()
{
    int Taille;

    cout << "combien d'éléments tu veut ?" << " ";
    cin >> Taille;

    int *notes = new int[Taille];

    for (int i = 0; i < Taille; i++)
    {
        cout << "Notes " << i + 1 << " : ";
        cin >> notes[i];
    }

    cout << "Voici tes notes : ";

    for (int i = 0; i < Taille; i++)
    {
        cout << notes[i] << " ";
    }

    cout << endl;

    delete[] notes;
}