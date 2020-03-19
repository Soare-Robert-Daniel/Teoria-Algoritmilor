#ifndef LAB2_H_INCLUDED
#define LAB2_H_INCLUDED

#include <iostream>

using namespace std;

bool validare_steag(int sol[8], int k) {
    for(int i = 1; i < k; ++i) {
        if(sol[i] == sol[k]) {
            return false;
        }
    }
    return true;
}

void generare_steag(int dim) {
    string culori[8] = {"","rosu", "oranj", "galben", "verde", "albastru", "indigo", "violet"};
    int sol[8], k = 1;
    bool ok = false;

    // Generare
    sol[k] = 0;
    while(k > 0) {
        ok = false;

        while( !ok && sol[k] + 1 <= 7 ) {
            sol[k] += 1;
            if(validare_steag(sol, k)) {
                ok = true;
            }
        }

        if(!ok) {
            k --;
        } else if(k == dim) {
            for(int i = 1; i <= dim; ++i) {
                cout << culori[sol[i]] <<" ";
                //cout << sol[i] <<" ";
            }
            cout << endl;
        } else {
            k ++;
            sol[k] = 0;
        }
    }
}

void generare_steag_3culori(int culoare_mijlor) {
    string culori[8] = {"","rosu", "oranj", "galben", "verde", "albastru", "indigo", "violet"};
    int sol[8], k = 1, dim = 2;
    bool ok = false;

    // Generare
    sol[k] = 0;
    while(k > 0) {
        ok = false;

        while( !ok && sol[k] + 1 <= 7 ) {
            sol[k] += 1;
            if(validare_steag(sol, k) && sol[k] != culoare_mijlor) {
                ok = true;
            }
        }

        if(!ok) {
            k --;
        } else if(k == dim) {
            cout << culori[sol[1]] <<" "<< culori[culoare_mijlor] <<" "<< culori[sol[2]];
            cout << endl;
        } else {
            k ++;
            sol[k] = 0;
        }
    }
}

bool validare_permutare(int sol[13], int k) {
    for(int i = 1; i < k; ++i) {
        if(sol[i] == sol[k]) {
            return false;
        }
    }
    return true;
}

bool validare_sume_muchii(int sol[13], int fete[6][4]) {
    int suma_necesara = 26;

    for(int fata = 0; fata < 6; fata++) {
        int suma_fata = 0;
        for(int i = 0; i < 4; ++i) {
            suma_fata += sol[fete[fata][i]];
        }

        if(suma_fata != suma_necesara) {
            return false;
        }
    }

    return true;
}

void generare_muchii_cub() {
    int sol[13], k = 1, nr_muchii = 12, dim = 12;
    int fete[6][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {7, 8, 9, 1},
        {6, 8, 10, 12},
        {2, 9, 10, 11},
        {3, 5, 12, 11}
    };

    bool ok = false;

    sol[k] = 0;

    while(k > 0) {
        ok = false;

        while( !ok && sol[k] + 1 <= nr_muchii) {
            sol[k] += 1;

            if(validare_permutare(sol, k)) {
                ok = true;
            }
        }

        if(!ok) {
            k --;
        } else if(k == nr_muchii && validare_sume_muchii(sol, fete)) {
            for(int i = 1; i <= dim; ++i) {
                cout << sol[i] <<" ";
            }

            cout << endl;
            for (int fata = 0; fata < 6; fata++)
            {
                cout << "Fata " << fata << ": ";
                for (int i = 0; i < 4; ++i)
                {
                    cout << sol[fete[fata][i]] << " ";
                }
                cout << endl;
            }

            cout << endl;
        } else {
            k ++;
            sol[k] = 0;
        }
    }
}

#endif
