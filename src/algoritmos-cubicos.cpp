#include<bits/stdc++.h>
#include "algoritmos-cubicos.h"
using namespace std;

//Algoritmo iteratio cubico
vector<vector<int>> multiplicacion_tradicional(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

//Algoritmo iterativo cubico optimizado
vector<vector<int>> transponer(const vector<vector<int>>& B) {
    int n = B.size();
    vector<vector<int>> B_T(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B_T[i][j] = B[j][i];
        }
    }
    return B_T;
}

vector<vector<int>> multiplicacion_optimizada(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    vector<vector<int>> B_T = transponer(B);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }
    return C;
}
