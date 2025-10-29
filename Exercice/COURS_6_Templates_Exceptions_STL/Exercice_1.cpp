#include <iostream>
using namespace std;

template <typename T>
T plusGrand(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << plusGrand(3, 7) << endl;
    cout << plusGrand(3.5, 2.1) << endl;
    cout << plusGrand('a', 'b') << endl;
}