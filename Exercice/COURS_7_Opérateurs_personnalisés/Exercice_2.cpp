#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> n = {10, 20, 30, 40, 50};

    sort(n.begin(), n.end(), [](int a, int b)
    {
        return a > b;
    });

    for (int valeur : n)
    {
        cout << valeur << " ";
    }

    return 0;
}


