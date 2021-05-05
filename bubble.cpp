#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream fin("date.in");
#include <chrono>
int v[10000000];

int bubble()
{
    int x, i, t = -1;

    while (fin >> x)
    {
        t++;
        v[t] = x;
    }

    int ok = 0, aux;
    do{
        ok = 0;
        for(i = 0; i < t; i++)
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;

                ok = 1; /// am facut o modificare
            }
    }while(ok);

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
    //int x;
    //x = bubble();
    //afisare(x);

    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    bubble();
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "timp:" << elapsed_seconds.count();

    return 0;
}
