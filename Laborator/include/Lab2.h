#ifndef LAB2_H_INCLUDED
#define LAB2_H_INCLUDED

#include <iostream>

using namespace std;

/*
                                DIVIDE ET IMPERA
*/

/*
    Sortare prin interclasare (Merge Sort)
*/
void interclasare(int *v, int stanga, int mijloc, int dreapta);
void merge_divide(int *v, int stanga, int dreapta);
void merge_sort(const int n, int *v);

void exemple_merge_sort()
{
    int n = 6;
    int v[6] = {3, -1, 2, 0, 1, 4};

    cout <<"# Merge sort\n";
    for(int i = 0; i < n; ++i)
    {
        cout << v[i] << " ";
    }
    cout << " -> ";

    merge_sort(n, v);

    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void merge_sort(const int n, int *v)
{
    merge_divide(v, 0, n - 1);
}

void merge_divide(int *v, int stanga, int dreapta)
{
    if(stanga < dreapta)
    {

        // impart problema in doua subprobleme
        int mijloc = (stanga + dreapta) / 2;
        merge_divide(v, stanga, mijloc);
        merge_divide(v, mijloc + 1, dreapta);

        // combin solutiile
        interclasare(v, stanga, mijloc, dreapta);
    }
}

void interclasare(int *v, int stanga, int mijloc, int dreapta)
{
    // definesc cei 2 vectori care urmeaza sa fie interclasati
    const int dd = dreapta - mijloc; // definesc dimensiunile vectorilor
    const int ds = mijloc - stanga + 1;
    int vs[ds], vd[dd];

    for(int i = 0; i < ds; ++i)
    {
        vs[i] = v[i + stanga];
    }

    for (int i = 0; i < dd; ++i)
    {
        vd[i] = v[i + (mijloc + 1)];
    }

    // interclasez cei 2 vectori
    int i = 0;   // iterator pentru vectorul stang
    int j = 0;   // iterator pentru vectorul drept
    int original = stanga;// iterator pentru vectorul `v` care va suprascrie vectorul original

    while(i < ds && j < dd)
    {
        if(vs[i] < vd[j])
        {
            v[original] = vs[i];
            i ++;
            original ++;
        }
        else
        {
            v[original] = vd[j];
            j++;
            original++;
        }
    }

    // pun elementele ramase
    for(int iter = i; iter < ds; ++iter )
    {
        v[original] = vs[iter];
        original++;
    }

    for (int iter = j; iter < dd; ++iter)
    {
        v[original] = vd[iter];
        original++;
    }
}

/*
    Turnurile din Haoi
*/

void hanoi(int discuri, int ia_din_tija, int pune_in_tija)
{
    if(discuri == 1)
    {
        cout << "Mut din " << ia_din_tija << " in " << pune_in_tija << endl;
    }
    else
    {
        int tija_suport = 6 - ia_din_tija - pune_in_tija;

        hanoi(discuri - 1, ia_din_tija, tija_suport);
        cout << "Mut din " << ia_din_tija << " in " << pune_in_tija << endl;
        hanoi(discuri - 1, tija_suport, pune_in_tija);
    }
}
void exemplu_turn_hanoi()
{
    cout << "# Hanoi cu 3 discuri\n";
    hanoi(3, 1, 2);
}

/*
    Cel mai mic divizor comun al unei multimi de numere
*/

int cmmdc_2(int a, int b);
int cmmdc(int *v, int stanga, int dreapta);

void exemplu_cmmdc()
{
    cout <<"# Cel mai mare divizor comun pentru o lista de numere\n";
    const int n = 6;
    int v[n] = {10, 15, 20, 25, 30, 35};
    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << " ";
    }
    cout << " -> CMMDC: " << cmmdc(v, 0, n - 1);
}

int cmmdc(int *v, int stanga, int dreapta)
{
    if(stanga == dreapta) {
        return v[stanga];
    }

    if(dreapta - stanga == 2) {
        return cmmdc_2(v[stanga], v[dreapta]);
    }

    int mijloc = (stanga + dreapta) / 2;

    int cmmmdc_stanga = cmmdc(v, stanga, mijloc);
    int cmmmdc_dreapta = cmmdc(v, mijloc + 1, dreapta);

    return cmmdc_2(cmmmdc_stanga, cmmmdc_dreapta);
}

int cmmdc_2(int a, int b)
{
    while (b != a)
    {
        if (a < b)
        {
            b -= a;
        }
        else
        {
            a -= b;
        }
    }

    return a;
}

#endif
