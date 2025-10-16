#include <iostream>
using namespace std;

class Personne
{
    public:
        string nom;
        int age;

        void presentation()
        {
            cout << "Bonjour, je m'appelle " << nom << " et j'ai " << age << " ans." << endl;
        }
};

int main()
{
    Personne p1;
    p1.nom = "Alice";
    p1.age = 30;

    Personne p2;
    p2.nom = "Bob";
    p2.age = 25;

    p1.presentation();
    p2.presentation();

    return 0;
}

