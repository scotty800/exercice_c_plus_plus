#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
using namespace std;

class Compte
{
protected:
        double solde;

public:

        Compte(double s = 0.0) : solde(s) {}

        virtual void display_info() const = 0;

        virtual void depot(double montant)
        {
            solde += montant;
            cout << "Dépôt de " << montant << " €. Nouveau solde: " << solde << "€\n";
        }
        
        virtual void retrait(double montant)
        {
            if (solde - montant < 0)
            throw runtime_error("Solde insuffisant pour effectuer le retrait.");
            
            solde -= montant;
            
            cout << "Retrait de " << montant << " €. Nouveau solde: " << solde << "€\n";
        }

        virtual ~Compte() {}

};

class CompteEpargne: public Compte
{
private:
        double taux;
    
public:
        CompteEpargne(double solde_init, double t)
            : Compte(solde_init), taux(t) {}

        void display_info() const override
        {
            cout << "[Compte Épargne]\n";
            cout << "Solde: " << solde << " €\n";
            cout << "Taux d'intérêt: " << taux << "%\n";
        }

};

int main()
{
    vector<unique_ptr<Compte>> comptes;
    
    comptes.push_back(make_unique<CompteEpargne>(100.0, 2.5));

    comptes[0]->display_info();

    try {
        comptes[0]->depot(50);
        comptes[0]->retrait(200);
    } catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    return 0; 
}