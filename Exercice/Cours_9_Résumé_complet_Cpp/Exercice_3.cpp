#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Logger
{
protected:
    vector<T> donnees;

public:
    Logger() {}

    void ajouter(const T& value)
    {
        donnees.push_back(value);
    }

    bool sauvegarder(const string& nomfichier)
    {
        ofstream fichier(nomfichier);

        if(!fichier.is_open())
        {
            return false;
        }

        for (const auto& d : donnees)
        {
            fichier << d << endl;
        }
        return true;
    }

    bool charger(const string& nomfichier)
    {
        ifstream fichier(nomfichier);

        if (!fichier.is_open())
            return false;

        donnees.clear();

        T valeur;
        while (fichier >> valeur)
        {
            donnees.push_back(valeur);
        }

        return true;
    }

    void afficher() const {
        for (const auto& d : donnees) {
            cout << d << endl;
        }
    }
};

int main()
{
    Logger<string> log;

    log.ajouter("Bonjour");
    log.ajouter("Je suis un test");

    log.sauvegarder("logs.txt");

    Logger<string> log2;
    log2.charger("logs.txt");

    log2.afficher();

    return 0;
}
