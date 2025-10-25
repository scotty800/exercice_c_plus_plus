#include <iostream>
using namespace std;

class Forme
{
    public:
        virtual double aire() = 0;        
};

class Cercle : public Forme
{
    private: 
        double Rayon;
    
    public:
        Cercle(double r)
        {
            Rayon = r;
        }
        
        double aire() override
        {
            double resultat = 3.14159 * Rayon * Rayon;
            cout << "Resultat = " << resultat << endl;

            return 0;
        }
};

class Rectangle : public Forme
{
    private:
        double Largeur;
        double hauteur;
    
    public:
        Rectangle(double l, double h)
        {
            Largeur = l;
            hauteur = h;
        }

        double aire() override
        {
            double resultat = Largeur * hauteur;
            cout << "Resultat = " << resultat << endl;

            return 0;
        }
};

int main()
{
    Cercle c(5.0);
    c.aire();

    Rectangle r(4.0, 5.0);
    r.aire();

    return 0;
}



