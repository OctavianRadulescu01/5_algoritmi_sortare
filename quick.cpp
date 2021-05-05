#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
ifstream fin("date.in");

int v[10000000];

int sortare(int st, int dr)
{
    int i, j, pivot;
    i = j = st;
    pivot = v[dr];
    for (i = st; i < dr; i++)
        if (v[i] <= v[dr])
        {
            swap(v[i], v[j]);
            j++;
        }
    swap(v[j], v[dr]);
    return j;
}

void quick(int v[10000000], int st, int dr)
{
    int i;
    if (st < dr)
    {
        i = sortare(st, dr);
        quick(v, st, i - 1);
        quick(v, i + 1, dr);
    }
}

void afisare(int x)
{
    int i;
    for (i = 0; i <= x; i++)
        cout << v[i] << " ";
}

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    int x, n;
    n = -1;
    while (fin >> x)
    {
        n++;
        v[n] = x;
    }
    quick(v, 0, n);
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "timp:" << elapsed_seconds.count();

    return 0;
}
