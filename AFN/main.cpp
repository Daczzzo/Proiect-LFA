#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int stareinit, starifin[10];
char cuvant[100];
int v[100], pozitiecur;
ifstream f("..//date.in");
struct tranzitie {
    int actual;
    char car;
    int urm;
} tranz[20];

/**
*
*@param stareact reprezinta nodul in care este programul in acest moment
*@param cuvant reprezinta un string care se modifica de la o apelare recursiva la alta
*eliminand prima litera a cuvantului
*@param nrmuchii este numarul total de muchii, fiecare muchie fiind reprezentata de o litera
*@param nrfin este numarul de stari finale ale automatului
*/

void automat(int stareact, char cuvant[100], int nrmuchii, int nrfin) {
    int i, OK = 0;
    char copiecuvant[100];
    if (cuvant[0] == NULL) {
        for (i = 0; i < nrfin; i++)
            if (stareact == starifin[i]) {
                v[pozitiecur] = 1;
                pozitiecur++;
                OK = 1;
            }
        if (OK == 0) {
            v[pozitiecur] = 0;
            pozitiecur++;
        }
    }
    for (i = 0; i < nrmuchii; i++)
        if (tranz[i].actual == stareact && cuvant[0] == tranz[i].car) {
            strcpy(copiecuvant, cuvant + 1);
            automat(tranz[i].urm, copiecuvant, nrmuchii, nrfin);
        }

}

int main() {
    int nrmuchii, nrfin;
    cout << "Introduceti starea initiala:";
    cin >> stareinit;
    cout << "Introduceti cate stari finale aveti:";
    cin >> nrfin;
    cout << "Introduceti starile finale:";
    int i, OK = 0;
    for (i = 0; i < nrfin; i++)
        cin >> starifin[i];
    f >> nrmuchii;
    for (i = 0; i < nrmuchii; i++) {
        f >> tranz[i].actual;
        f >> tranz[i].car;
        f >> tranz[i].urm;
    }
    cout << "Introduceti cuvantul:" << endl;
    cin >> cuvant;
    cout << endl;
    automat(stareinit, cuvant, nrmuchii, nrfin);
    for (i = 0; i < pozitiecur; i++)
        if (v[i] == 1 && OK == 0) {
            OK = 1;
            cout << "cuvantul apartine" << endl;
        }
    if (OK == 0)
        cout << "cuvantul nu apartine";
    return 0;
}
