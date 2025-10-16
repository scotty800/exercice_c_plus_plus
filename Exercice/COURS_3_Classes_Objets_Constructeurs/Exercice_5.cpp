#include <iostream>
using namespace std;

class Rectangle
{
    private:
        double largeur;
        double hauteur;

    public:
        // Constructeur
        Rectangle(double l, double h)
        {
            largeur = l;
            hauteur = h;
        }

        double aire()
        {
            return largeur * hauteur;
        }

        double perimetre()
        {
            return 2 * (largeur + hauteur);
        }
};

class carre : public Rectangle
{
    public:
        // Constructeur
        carre(double cote) : 
        Rectangle(cote, cote) {}
};

int main()
{
    Rectangle rect(4.0, 5.0);
    cout << "Aire du rectangle: " << rect.aire() << endl;
    cout << "Périmètre du rectangle: " << rect.perimetre() << endl;

    carre c(4.0);
    cout << "Aire du carré: " << c.aire() << endl;
    cout << "Périmètre du carré: " << c.perimetre() << endl;

    return 0;
}