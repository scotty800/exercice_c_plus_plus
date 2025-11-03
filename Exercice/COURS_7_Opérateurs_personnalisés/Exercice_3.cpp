#include <iostream>
#include <memory>
using namespace std;

class Personne
{
    private:
        string nom;
    public:
        Personne(string n) : nom(n) {}
};

int main()
{
    shared_ptr<Personne> p1 = make_shared<Personne>("Alice");
    shared_ptr<Personne> p2 = p1;

    cout << "Nombre de references: " << p1.use_count() << endl;
}