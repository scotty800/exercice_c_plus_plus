#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Entrez un nombre entier : ";
    cin >> num;

    if (num % 2 == 0) {
        cout << num << " est un nombre pair." << endl;
    }
    else {
        cout << num << " est un nombre impair." << endl;
    }

    return 0;
}