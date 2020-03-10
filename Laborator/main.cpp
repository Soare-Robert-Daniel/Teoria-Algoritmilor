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


int main()
{
    generare_steag(3);
    return 0;
}
