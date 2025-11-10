#include<iostream>
using namespace std;

template <typename T1, typename T2, typename T3>
class Triplet 
{
    private:
        T1 v1; 
        T2 v2; 
        T3 v3;
        
    public:
        Triplet(T1 a, T2 b, T3 c)
        {
            v1 = a;
            v2 = b;
            v3 = c;
        }

        void afficher()
        {
            cout << "Triplet: (" << v1 << ", " << v2 << ", " << v3 << ")" << endl;
        }
};

int main()
{
    Triplet<int, double, string> triplet(1, 2.5, "example");
    triplet.afficher();
    return 0;
}