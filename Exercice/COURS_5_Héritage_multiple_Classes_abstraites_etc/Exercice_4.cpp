#include <iostream>
using namespace std;

class Humain
{
    public:
        virtual ~Humain()
        {
            cout << "Destructeur Humain" << endl;
        }
};

class Naruto : public Humain
{
    public:
        ~Naruto()
        {
            cout << "Destructeur Naruto" << endl;
        }
};

int main()
{
    Humain *h = new Naruto();
    delete h;
}