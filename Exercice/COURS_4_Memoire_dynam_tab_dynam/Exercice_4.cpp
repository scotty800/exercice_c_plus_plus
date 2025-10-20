#include <iostream>
using namespace std;

class Tableau
{
    private:
        int *data;
        int Taille;
    
    public:
        Tableau(int n) {
            Taille = n;
            data = new int[Taille];
        }

        Tableau(const Tableau &autre)
        {
            Taille = autre.Taille;
            data = new int[Taille];

            for (int i = 0; i < Taille; i++)
            {
                data[i] = autre.data[i];
            }
        }

        ~Tableau()
        {
            delete[] data;
        }

        void remplir()
        {
            for (int i = 0; i < Taille; i++)
            {
                cout << "Valeur " << i + 1 << " : ";
                cin >> data[i];
            }
        }

        void afficher()
        {
            for (int i = 0; i < Taille; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }

        void somme()
        {
            int somme = 0;

            for (int i = 0; i < Taille; i++)
            {
                somme += data[i];
            }

            cout << somme << endl;
        }
};

int main()
{
    Tableau t(4);
    t.remplir();
    t.afficher();
    t.somme();

    return 0;
}