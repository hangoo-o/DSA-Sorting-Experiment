#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

const int N = 1000000;

bool DocFile(string filename, double a[])
{
    ifstream fin(filename);

    if (!fin)
        return false;

    for (int i = 0; i < N; i++)
        fin >> a[i];

    fin.close();
    return true;
}

int main()
{
    double *a = new double[N];

    string files[10] =
    {
        "data/data01_ascending.txt",
        "data/data02_descending.txt",
        "data/data03_random.txt",
        "data/data04_random.txt",
        "data/data05_random.txt",
        "data/data06_random.txt",
        "data/data07_random.txt",
        "data/data08_random.txt",
        "data/data09_random.txt",
        "data/data10_random.txt"
    };

    for (int k = 0; k < 10; k++)
    {
        if (!DocFile(files[k], a))
        {
            cout << "Khong mo duoc file " << files[k] << endl;
            continue;
        }

        auto start = high_resolution_clock::now();

        sort(a, a + N);

        auto end = high_resolution_clock::now();

        auto time =
            duration_cast<milliseconds>(end - start).count();

        cout << "Data " << k + 1
             << ": " << time << " ms" << endl;
    }

    delete[] a;

    return 0;
}