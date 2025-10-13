#include <iostream>
using namespace std;

typedef struct Etudiant
{
    string nom;
    int age;
    double moyenne;
} Etudiant;

void afficherEtudiant(const Etudiant &e)
{
    cout << "Nom: " << e.nom << ", Age: " << e.age << ", Moyenne: " << e.moyenne << endl;
}

int main()
{
    Etudiant etu1 = {"Alice", 20, 15.5};
    Etudiant etu2 = {"Bob", 22, 14.0};

    afficherEtudiant(etu1);
    afficherEtudiant(etu2);

    return 0;
}