#include <iostream>
using namespace std;

class Marcher
{
    public:
        void marcher()
        {
            cout << "Marcher" << endl;
        }
};

class Voler
{
    public:
        void voler()
        {
            cout << "Voler" << endl;
        }
};

class SuperHero : public Marcher, public Voler
{
    public:
        void presentation()
        {
            cout << "je suis Superman" << endl;
        }
};

int main()
{
    SuperHero h;
    h.marcher();
    h.voler();
    h.presentation();

    return 0;
}
