#include <iostream>
#include <thread>
#include <vector>
#include <memory>

using namespace std;

class Personnage;

template <typename T>
class Objet 
{
private:
    string nom;
    T valeur;

public:
    Objet(const string &n, T v)
    {
        nom = n;
        valeur = v;
    }

    void utiliser(Personnage &cible);
};

class Personnage
{
protected:
    string nom;
    int hp;
    int mp;
    int attaque;
    int defense;

public:
    virtual void attaquer(Personnage &cible) = 0;
    virtual void defendre(int degats) = 0;

    virtual void ajouterObjet(const Objet<int> obj) {
        cout << nom << " ne peut pas avoir d'inventaire.\n";
    }
    virtual void utiliserObjet(int index, Personnage& cible) {
        cout << nom << " n'a pas d'objets.\n";
    }

    virtual void lancerSort(Personnage &cible, string sort) {
        cout << nom << " ne peut pas lancer de sorts.\n";
    }

    int getDefense() const {
        return defense;
    }

    int getHp() const {
        return hp;
    }

    int getMp() const {
        return mp;
    }

    bool estVivant()
    {
        return hp > 0;
    }

    void afficherStats()
    {
        cout << nom << " | HP : " << hp << " | ATK : " << attaque << " | DEF : " << defense << endl;
    }
    

    virtual ~Personnage()
    {
        cout << "Destructeur Personnage" << endl;
    }

};


class Guerrier : public Personnage
{

private:
    vector<Objet<int>> inventaire;

public:
    Guerrier(const string &n, int h, int a, int d)
    {
        nom = n;
        hp = h;
        mp = 0;
        attaque = a;
        defense = d;
    }

    void attaquer(Personnage & cible) override
    {
        int degats = attaque - cible.getDefense();
        if (degats < 0) {
            degats = 0;
        }
        cible.defendre(degats);
    }

    void defendre(int degats) override
    {
        hp -= degats;
        if (hp < 0) {
            hp = 0;
        }
    }

    void ajouterObjet(Objet<int> obj)
    {
        inventaire.push_back(obj);
    }
    void utiliserObjet(int index, Personnage& cible)
    {
        if (index < 0 || index >= inventaire.size())
        {
            cout << "Index invalide !" << endl;
            return;
        }

        inventaire[index].utiliser(cible);

        inventaire.erase(inventaire.begin() + index);
    }
};

class Mage : public Personnage
{

private:
    vector<Objet<int>> inventaire;

public:
    Mage(const string &n, int h, int m, int a, int d)
    {
        nom = n;
        hp = h;
        mp = m;
        attaque = a;
        defense = d;
    }

    void attaquer(Personnage &cible) override
    {
        int degats = attaque - cible.getDefense();
        if (degats < 0) {
            degats = 0;
        }
        cible.defendre(degats);
    }

    void defendre(int degats) override
    {
        hp -= degats;
        if (hp < 0)
        {
            hp = 0;
        }
    }

    void lancerSort(Personnage &cible, string sort)
    {
        int degat_sort = attaque - cible.getDefense();

        if (mp > 0)
        {
            cout << sort << " inflige " << degat_sort << " dégàts !" << endl;
            cible.defendre(degat_sort);
        }
    }

    void ajouterObjet(Objet<int> obj)
    {
        inventaire.push_back(obj);
    }

    void utiliserObjet(int index, Personnage& cible)
    {
        if (index < 0 || index >= inventaire.size())
        {
            cout << "Index invalide !" << endl;
            return;
        }

        inventaire[index].utiliser(cible);

        inventaire.erase(inventaire.begin() + index);
    }
};

class Monstre : public Personnage
{
public:
    Monstre(const string &n, int h, int a)
    {
        nom = n;
        hp = h;
        attaque = a;
    }

    void attaquer(Personnage & cible) override
    {
        int degats = attaque - cible.getDefense();
        if (degats < 0)
        {
            degats = 0;
        }
        cible.defendre(degats);
    }

    void defendre(int degats) override
    {
        hp -= degats;
        if (hp < 0)
        {
            hp = 0;
        }
    }
};

template <typename T>
void Objet<T>::utiliser(Personnage &cible)
{
    if (valeur > 0) {
        cout << nom << " soigne " << valeur << " HP ! " << endl;
        cible.defendre(-valeur);
    }
    else {
        cout << nom << " inflige " << -valeur << " dégâts !" << endl;
        cible.defendre(-valeur);
    }
}


int main()
{
    int i;
    Personnage *p[2];
    p[0] = new Guerrier("king", 100, 110, 80);
    p[1] = new Mage("Sorciere", 100, 100, 120, 50);

    p[0]->afficherStats();
    p[1]->afficherStats();

    p[0]->attaquer(*p[1]);

    p[0]->afficherStats();
    p[1]->afficherStats();

    Objet<int> potion("Potion de soin", 50);

    p[1]->ajouterObjet(potion);
    p[1]->utiliserObjet(0, *p[1]);

    vector<shared_ptr<Monstre>> monstres;
    monstres.push_back(make_shared<Monstre>("Goblin", 80, 30));
    monstres.push_back(make_shared<Monstre>("Orc", 120, 40));

    monstres[0]->attaquer(*p[0]);
    p[0]->afficherStats();
    monstres[1]->attaquer(*p[1]);
    p[1]->afficherStats();


    for (auto& m : monstres)
    {
        m->afficherStats();
    }

    vector<thread> threads;

    for (auto& m : monstres)
    {
        threads.emplace_back([&]() {
            m->attaquer(*p[0]);
        });
    }

    for (auto& t : threads)
    {
        t.join();
    }


    for (int i = 0; i < 3; i++)
    {
        p[0]->attaquer(*monstres[0]);
        p[1]->lancerSort(*monstres[1], "Boule de feu");
        monstres[0]->attaquer(*p[0]);
        p[0]->estVivant() ? p[0]->afficherStats() : void(printf("Le guerrier est mort.\n"));
        p[1]->estVivant() ? p[1]->afficherStats() : void(printf("Le mage est mort.\n"));
        monstres[0]->estVivant() ? monstres[0]->afficherStats() : void(printf("Le monstre 1 est mort.\n"));
        monstres[1]->estVivant() ? monstres[1]->afficherStats() : void(printf("Le monstre 2 est mort.\n"));
    }

}