#include <iostream>
using namespace std;

class Complexe
{
private:
    double reel;
    double imaginaire;

public:
    Complexe(double r, double i) : reel(r), imaginaire(i) {}

    Complexe operator+(const Complexe &autre)
    {
        return Complexe(reel + autre.reel, imaginaire + autre.imaginaire);
    }

    bool operator==(const Complexe &autre)
    {
        return (reel == autre.reel) && (imaginaire == autre.imaginaire);
    }

    void afficher() const
    {
        cout << reel << " + " << imaginaire << "i" << endl;
    }
};

int main()
{
    Complexe c1(2.0, 3.0);
    Complexe c2(4.0, 5.0);
    Complexe c3 = c1 + c2;

    cout << "Résultat de l'addition : ";
    c3.afficher();

    if (c1 == c2)
        cout << "Les deux complexes sont égaux." << endl;
    else
        cout << "Les deux complexes sont différents." << endl;

    return 0;
}
