#include <iostream>
#include <stdexcept> // pour runtime_error
using namespace std;

int retirer(int montant, int solde)
{
    if (montant > solde)
    {
        throw runtime_error("Fonds insuffisants pour le retraits.");
    }
    
    return solde - montant;
}

int main()
{
    int solde = 100;

    try {
        solde = retirer(50, solde);
        solde = retirer(150, solde);
        cout << "Nouveau solde : " << solde << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    cout << "Programme termine." << endl;
    return 0;
}