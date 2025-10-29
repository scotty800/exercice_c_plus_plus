#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nombre = {2, 5, 8, 1, 4};

    sort(nombre.begin(), nombre.end());

    nombre.push_back(10);

    for(int n : nombre)
    {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}