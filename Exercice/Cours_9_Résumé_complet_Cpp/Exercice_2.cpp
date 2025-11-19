#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <string>
using namespace std;

class Personnage
{
protected:
        string name;
        vector<string> inventaire;

public:
        Personnage(string n) : name(n){}

        void ajouterItem(const string& item)
        {
            inventaire.push_back(item);
        }

        virtual void Attack() const = 0;

        virtual ~Personnage() {};
};

class Mage: public Personnage
{
public:
        Mage(string n) : Personnage(n) {}

        void Attack() const override
        {
            cout << name << " Attack magique boule de feu" << endl;
        }
};

class Guerrier: public Personnage
{
public:
        Guerrier(string n) : Personnage(n) {}

        void Attack() const override
        {
            cout << name << " Attack coup d'épée" << endl;
        }
};

int main()
{
    unique_ptr<Personnage> mage = make_unique<Mage>("Gandalf");
    unique_ptr<Personnage> guerrier = make_unique<Guerrier>("Conan");

    mage->ajouterItem("Bâton");
    mage->ajouterItem("Potion de mana");

    guerrier->ajouterItem("Epée");
    guerrier->ajouterItem("Bouclier");

    thread t1(&Personnage::Attack, mage.get());
    thread t2(&Personnage::Attack, guerrier.get());

    t1.join();
    t2.join();

    return 0;
}
