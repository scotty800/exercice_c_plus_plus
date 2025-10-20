#include <iostream>
using namespace std;

class Complexe 
{
    public:
        double reel;
        double imag;

        Complexe(double a, double b)
        {
            reel = a;
            imag = b;
        }
    
        Complexe operator+(const Complexe &autre) {
            return Complexe(reel + autre.reel, imag + autre.imag);
        }

        friend ostream &operator<<(ostream &out, const Complexe &p) {
            out << "(" << p.reel << ", " << p.imag << ")";
            return out;
        }
};

int main()
{
    Complexe a(2, 3), b(4, 5);
    Complexe res = a + b;

    cout << "resultat = " << res << endl;

    return 0;
}