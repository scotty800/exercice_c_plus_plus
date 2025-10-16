#include <iostream>
using namespace std;

class Personne
{
    public:
        string nom;
        int age;

        Personne(string n, int a)
        {
            nom = n;
            age = a;
        }

        void presentation()
        {
            cout << "Bonjour, je m'appelle " << nom << " et j'ai " << age << " ans." << endl;
        }
};

int main()
{
    Personne p1("Alice", 30);
    Personne p2("Bob", 25);

    p1.presentation();
    p2.presentation();

    return 0;
}

