#include <iostream>
using namespace std;

int main() {
    int age;
    string name;
    cout << "Quelle est votre nom ? " << endl;
    cin >> name;
    cout << "Quelle est votre age ? " << endl;
    cin >> age;
    cout << "Bonjour " << name << ", vous avez " << age << " ans." << endl;

    return 0;
}