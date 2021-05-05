#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
ifstream f("date.in");

int v[1000000];
int aux[1000000];

void interclasare(int i, int j, int sti, int stj)
{
    int poz;

    for (poz = i; poz <= stj; poz++)
        aux[poz] = v[poz];

    int k = i - 1;
    while(i <= sti && j <= stj)
    {
        if (aux[i] < aux[j])
            v[++k] = aux[i++];
        else
            v[++k] = aux[j++];
    }
    for(;i <= sti; i++)
        v[++k] = aux[i++];
    for(;j <= stj; j++)
        v[++k] = aux[j++];
}

int mergesort()
{
    int x, n = -1, pas, i, j, p, tt, sti, stj;
    while(f >> x)
        v[++n] = x;

    i = 0; tt = 1;

    pas = 1;
    while (pas <= n / 2 && tt <= n)
    {
        tt *= 2;
        for (i = 0; i <= n; i += tt)
        {
            stj = i + tt - 1; /// stop j
                if (stj > n) stj = n;
            sti = i + tt / 2 - 1;
            j = i + tt / 2;
                if (j > n) j = n;
            if (sti > n)
                break;
            ///cout << i << " " << sti << " " << j << " " << stj << endl;
            interclasare(i, j, sti, stj);
        }
        pas += 1;
    }

    if (n % 2 == 1)
    {
        tt *= 2;
        for (i = 0; i <= n; i += tt)
        {
            stj = i + tt - 1; /// stop j
                if (stj > n) stj = n;
            sti = i + tt / 2 - 1;
            j = i + tt / 2;
                if (j > n) j = n;
            if (sti > n)
                break;
            interclasare(i, j, sti, stj);
            ///cout << i << " " << sti << " " << j << " " << stj << endl;
        }
    }

    return n;
}

void afisare(int n)
{
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
}

int main()
{
///    int r;
///    r = mergesort();
///    afisare(r);
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    mergesort();
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "timp:" << elapsed_seconds.count();

    return 0;
    return 0;
}
