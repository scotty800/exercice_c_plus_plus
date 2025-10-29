#include <iostream>
using namespace std;

template <typename T>
class Paire
{
    private:
        T premier;
        T second;
    public:
        Paire(T a, T b) : premier(a), second(b) {}
    
        void afficher()
        {
            cout << "Paire: (" << premier << ", " << second << ")" << endl;
        }
};

int main()
{
    Paire<int> p1(3, 7);
    p1.afficher();

    Paire<double> p2(3.5, 2.1);
    p2.afficher();

    Paire<char> p3('a', 'b');
    p3.afficher();

    return 0;
}