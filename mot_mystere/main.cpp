//mot mystere exo: choix du mot mystere, on montre le mot en collection arbitraire 
// de lettres, on joue après pour trouver l'ordre de la collection
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string melangerLettres(string mot)
{
    string melange;
    int position(0);

    // Tant que nous n'avons pas extrait toutes les lettres du mot
    while (mot.size() != 0)
    {
        // On choisit un num�ro de lettre au hasard dans le mot
        position = rand() % mot.size();
        // On ajoute la lettre dans le mot m�lang�
        melange += mot[position];
        // On retire cette lettre du mot myst�re pour ne pas la prendre une 2e fois
        mot.erase(position, 1);
    }

    // On renvoie le mot m�lang�
    return melange;
}

int main()
{
    string motMystere, motMelange, motUtilisateur;

    // Initialisation des nombres al�atoires
    srand(time(0));


    // 1 : On demande � saisir un mot
    cout << "Saisissez un mot" << endl;
    cin >> motMystere;

    // 2 : On r�cup�re le mot avec les lettre m�lang�es dans motMelange
    motMelange = melangerLettres(motMystere);

    // 3 : On demande � l'utilisateur quel est le mot myst�re
    do
    {
        cout << endl << "Quel est ce mot ? " << motMelange << endl;
        cin >> motUtilisateur;

        if (motUtilisateur == motMystere)
        {
            cout << "Bravo !" << endl;
        }
        else
        {
            cout << "Ce n'est pas le mot !" << endl;
        }
    }while (motUtilisateur != motMystere); // On recommence tant qu'il n'a pas trouv�

    return 0;
}
