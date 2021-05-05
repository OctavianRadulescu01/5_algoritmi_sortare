#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

ifstream fin("date.in");

int v[10000000];

int selection()
{
    int x, a, b, aux, minn, i = -1;
    while(fin>>x)
    {
        i++;
        v[i] = x;
    }

    for (a = 0; a < i; a++)
    {
        minn = a;
        for (b = a + 1; b <= i; b++)
            if (v[b] < v[minn])
                minn = b;
        aux = v[a];
        v[a] = v[minn];
        v[minn] = aux;
    }
    return i;
}

void afisare(int x)
{
    int i;
    for (i = 0; i <= x; i++)
        cout << v[i] << " ";
}

int main()
{
    //int x;
    //x = selection();
    //afisare(x);

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    selection();
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "timp:" << elapsed_seconds.count();

    return 0;
}
