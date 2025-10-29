#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, float> produit;

    produit["Pomme"] = 3.5;
    produit["Banane"] = 2.0;
    produit["Orange"] = 5.0;

    for (const auto& [key, value] : produit)
    {
        cout << key << ": " << value << endl;
    }

    if (produit.find("Banane") != produit.end())
    {
        cout << "Le produit 'Banane' est present." << endl;
    }
    return 0;
}