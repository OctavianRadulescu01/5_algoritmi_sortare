#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
ifstream fin("date.in");

int v[10000000];

int insertion()
{
    int x, i, j, aux, t = -1;

    while (fin >> x)
    {
        t++;
        v[t] = x;
    }

    for(i = 0; i <= t; i++)
    {
        j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            aux = v[j];
            v[j] = v[j - 1];
            v[j - 1] = aux;
            j--;
        }
    }
    return t;
}

void afisare(int x)
{
    int i;
    for (i = 0; i <= x; i++)
        cout << v[i] << " ";
}

int main()
{
//    int x;
//    x = insertion();
//    afisare(x);

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    insertion();
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "timp:" << elapsed_seconds.count();

    return 0;
}
