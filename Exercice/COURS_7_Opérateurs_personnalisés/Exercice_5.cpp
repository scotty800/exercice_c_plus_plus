#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Etudiant {
private:
    string nom;
    double moyenne;

public:
    Etudiant() {}
    Etudiant(string n, double m) : nom(n), moyenne(m) {}

    void saisir() {
        cout << "Nom de l'étudiant : ";
        cin >> nom;
        cout << "Moyenne : ";
        cin >> moyenne;
    }

    void afficher() const {
        cout << nom << " - Moyenne : " << moyenne << endl;
    }

    double getMoyenne() const { return moyenne; }
    string getNom() const { return nom; }
};

int main() {
    vector<Etudiant> etudiants;
    int nb;
    cout << "Combien d'étudiants veux-tu enregistrer ? ";
    cin >> nb;


    ofstream fichier("etudiants.txt");
    if (!fichier) {
        cerr << "Erreur d'ouverture du fichier !" << endl;
        return 1;
    }

    for (int i = 0; i < nb; i++) {
        Etudiant e;
        e.saisir();
        fichier << e.getNom() << " " << e.getMoyenne() << endl;
    }
    fichier.close();

    
    ifstream fichierLecture("etudiants.txt");
    if (!fichierLecture) {
        cerr << "Erreur lors de la lecture du fichier !" << endl;
        return 1;
    }

    cout << "\nÉtudiants avec une moyenne > 10 :\n";
    string nom;
    double moy;
    while (fichierLecture >> nom >> moy) {
        if (moy > 10) {
            cout << nom << " - Moyenne : " << moy << endl;
        }
    }

    fichierLecture.close();
    return 0;
}
