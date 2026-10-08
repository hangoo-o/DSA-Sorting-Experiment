#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

const int N = 1000000;

void Heapify(double a[], int k, int n)
{
    int j = 2 * k + 1;

    while (j < n)
    {
        if (j + 1 < n && a[j] < a[j + 1])
            j++;

        if (a[k] >= a[j])
            return;

        swap(a[k], a[j]);

        k = j;
        j = 2 * k + 1;
    }
}

void BuildHeap(double a[], int n)
{
    int i = (n - 1) / 2;

    while (i >= 0)
    {
        Heapify(a, i, n);
        i--;
    }
}

void HeapSort(double a[], int n)
{
    BuildHeap(a, n);

    while (n > 1)
    {
        n--;

        swap(a[0], a[n]);

        Heapify(a, 0, n);
    }
}

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

        HeapSort(a, N);

        auto end = high_resolution_clock::now();

        auto time =
            duration_cast<milliseconds>(end - start).count();

        cout << "Data " << k + 1
             << ": " << time << " ms" << endl;
    }

    delete[] a;

    return 0;
}