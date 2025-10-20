#include <iostream>
using namespace std;

class Personnes
{
    public:
        Personnes() {
            cout << "Création d'une personne !" << endl; 
        }

        ~Personnes() {
            cout << "Suppression d'une personne !" << endl;
        }
};

int main()
{
    Personnes p;
}