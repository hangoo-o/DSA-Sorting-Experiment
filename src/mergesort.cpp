#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

const int N = 1000000;

void Merge(double a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double *L = new double[n1];
    double *R = new double[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void MergeSort(double a[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);

    Merge(a, left, mid, right);
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

        MergeSort(a, 0, N - 1);

        auto end = high_resolution_clock::now();

        auto time =
            duration_cast<milliseconds>(end - start).count();

        cout << "Data " << k + 1
             << ": " << time << " ms" << endl;
    }

    delete[] a;

    return 0;
}