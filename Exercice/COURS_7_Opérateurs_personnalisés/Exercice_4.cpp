#include <iostream>
#include <fstream>
using namespace std;

int main() {

    int age = 0;
    string nom;

    cout << "Quelle est votre nom ? ";
    cin >> nom;
    cout << "Quel est votre age ? ";
    cin >> age;

    ofstream fichier("personnes.txt");
    fichier << "Nom: " << nom << endl;
    fichier << "Age: " << age << endl;
    fichier.close();

    ifstream fichierLecture("personnes.txt");
    string ligne;

    while (getline(fichierLecture, ligne)) {
        cout << ligne << endl;
    }
    fichierLecture.close();

    return 0;
}