#include <iostream>
using namespace std;

class Vehicule
{
    public:
        virtual void deplacer() = 0;
};

class Voiture : public Vehicule
{
    public:
        void deplacer() override
        {
            cout << "Je roule sur la route" << endl;
        }
};

class Bateau : public Vehicule
{
    void deplacer() override
    {
        cout << "Je navigue sur l'eau" << endl;
    }
};

int main()
{
    int i;
    Vehicule *v[2];
    v[0] = new Voiture;
    v[1] = new Bateau;

    for(i = 0; i < 2; i++)
    {
        v[i]->deplacer();
        delete v[i];
    }
    
    return 0;
}