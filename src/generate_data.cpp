#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000000;

void saveFile(string filename, const vector<double>& a)
{
    ofstream fout(filename);

    for (double x : a)
        fout << x << '\n';

    fout.close();
}

int main()
{
    vector<double> a(N);

    // Data 1: tang dan
    for (int i = 0; i < N; i++)
        a[i] = i + 0.5;

    saveFile("data/data01_ascending.txt", a);

    // Data 2: giam dan
    reverse(a.begin(), a.end());

    saveFile("data/data02_descending.txt", a);

    // Data 3 -> 10: ngau nhien
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> dis(0, 1000000);

    for (int k = 3; k <= 10; k++)
{
    for (int i = 0; i < N; i++)
        a[i] = dis(gen);

    string filename = "data/data";

    if (k < 10)
        filename += "0";

    filename += to_string(k);
    filename += "_random.txt";

    saveFile(filename, a);
}
    cout << "Da tao xong 10 bo du lieu!\n";

    return 0;
}