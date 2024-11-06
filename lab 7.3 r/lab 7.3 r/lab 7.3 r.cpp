#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1) {
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
    }
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo) {
    if (rowNo < K) {
        CreateRow(a, rowNo, N, Low, High, 0);
        CreateRows(a, K, N, Low, High, rowNo + 1);
    }
}

void PrintRow(int** a, const int rowNo, const int N, int colNo) {
    if (colNo < N) {
        cout << setw(4) << a[rowNo][colNo];
        PrintRow(a, rowNo, N, colNo + 1);
    }
    else {
        cout << endl;
    }
}

void PrintRows(int** a, const int K, const int N, int rowNo) {
    if (rowNo < K) {
        PrintRow(a, rowNo, N, 0);
        PrintRows(a, K, N, rowNo + 1);
    }
}

void GaussianElimination(int** a, const int K, const int N) {
    for (int i = 0; i < K - 1; i++) {
        for (int j = i + 1; j < K; j++) {
            if (a[i][i] != 0) {
                double factor = static_cast<double>(a[j][i]) / a[i][i];
                for (int k = i; k < N; k++) {
                    a[j][k] -= factor * a[i][k];
                }
            }
        }
    }
}

int CountRowsWithMeanBelow(int** a, const int K, const int N, double threshold) {
    int count = 0;
    for (int i = 0; i < K; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += a[i][j];
        }
        double mean = static_cast<double>(sum) / N;
        if (mean < threshold) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Low = -10;
    int High = 10;
    int K, N;

    cout << "Введіть кількість рядків матриці (K): ";
    cin >> K;
    cout << "Введіть кількість стовпців матриці (N): ";
    cin >> N;

    int** a = new int* [K];
    for (int i = 0; i < K; i++)
        a[i] = new int[N];

    CreateRows(a, K, N, Low, High, 0);
    cout << "Початкова матриця:" << endl;
    PrintRows(a, K, N, 0);

    GaussianElimination(a, K, N);
    cout << "Матриця після приведення до трикутного вигляду:" << endl;
    PrintRows(a, K, N, 0);

    double threshold;
    cout << "Введіть порогове значення для середнього арифметичного: ";
    cin >> threshold;

    int count = CountRowsWithMeanBelow(a, K, N, threshold);
    cout << "Кількість рядків, середнє арифметичне елементів яких менше " << threshold << ": " << count << endl;

    for (int i = 0; i < K; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
