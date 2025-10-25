#include <iostream>
using namespace std;

class Animal
{
    public:
        virtual void parler() = 0;
};

class Chat : public Animal
{
    public:
        void parler() override
        {
            cout << "Miaou" << endl;
        }
};

class Chien : public Animal
{
    public:
        void parler() override
        {
            cout << "Ouaf" << endl;
        }
};

class Oiseau : public Animal
{
    public:
        void parler() override
        {
            cout << "Pik" << endl;
        }
};

int main()
{
    Animal *a1 = new Chat();
    Animal *a2 = new Chien();
    Animal *a3 = new Oiseau();

    a1->parler();
    a2->parler();
    a3->parler();

    delete a1;
    delete a2;
    delete a3;

    return 0;
}