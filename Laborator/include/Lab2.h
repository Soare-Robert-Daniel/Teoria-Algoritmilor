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
    for(int i = 0; i < n; ++i) {
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
#endif
