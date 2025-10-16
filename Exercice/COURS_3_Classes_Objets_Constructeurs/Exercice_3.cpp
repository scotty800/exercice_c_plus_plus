#include <iostream>
using namespace std;

class Compte
{
    private:
        double solde;

    public:
        void deposer(double montant)
        {
            solde += montant;
        }
        
        void retirer(double montant)
        {
            solde -= montant;
        }

        void afficherSolde()
        {
            cout << "Solde actuel: " << solde << " euros" << endl;
        }
};

int main()
{
    Compte c;
    c.deposer(1000);
    c.afficherSolde();
    c.retirer(250);
    c.afficherSolde();
}