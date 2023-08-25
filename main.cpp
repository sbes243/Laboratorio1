#include <ctime>
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <vector>


using namespace std;
#define MAX 2000

int main() {
    vector<vector<double>> A;
    vector<double> x;
    vector<double> y;
    for (int i = 0; i < MAX; i++) {
        vector<double> vec1;
        for (int j = 0; j < MAX; j++) {
            vec1.push_back(3);
        }
        A.push_back(vec1);
    }
    for (int i = 0; i < MAX; i++) {
        y.push_back(0);
    }
    for (int i = 0; i < MAX; i++) {
        x.push_back(i);
    }
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += (A[i][j]) * x[j];
        }
    }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }
    start = chrono::steady_clock::now();
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += (A[i][j]) * x[j];
        }
    }
    end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
}
