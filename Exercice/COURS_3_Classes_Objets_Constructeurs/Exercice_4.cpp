#include <iostream>
using namespace std;

class Animal
{
    public:
        string nom;

        void parler()
        {
            cout << nom << " fait un bruit." << endl;
        }
};

class Chat: public Animal
{
    public:
        void miauler()
        {
            cout << nom << " dit Miaou!" << endl;
        }
};

int main()
{
    Chat c;
    c.nom = "Whiskers";
    c.parler();
    c.miauler();

    return 0;
}