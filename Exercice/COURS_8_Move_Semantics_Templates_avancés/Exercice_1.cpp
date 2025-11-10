#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1(100000, 42);

    cout << "Avant move:" << endl;
    cout << "v1 size: " << v1.size() << endl;

    vector<int> v2 = move(v1);

    cout << "\nAprès move:" << endl;
    cout << "v1 size: " << v1.size() << endl; // doit être 0
    cout << "v2 size: " << v2.size() << endl; // doit être 100000

    return 0;
}
