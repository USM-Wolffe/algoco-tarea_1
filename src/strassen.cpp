#include <vector>
#include "strassen.h"

using namespace std;

// Función para sumar dos matrices
vector<vector<int>> sumar_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Función para restar dos matrices
vector<vector<int>> restar_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Función de Strassen para la multiplicación de matrices
vector<vector<int>> strassen_multiplicacion(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    vector<vector<int>> a11(newSize, vector<int>(newSize)),
                        a12(newSize, vector<int>(newSize)),
                        a21(newSize, vector<int>(newSize)),
                        a22(newSize, vector<int>(newSize)),
                        b11(newSize, vector<int>(newSize)),
                        b12(newSize, vector<int>(newSize)),
                        b21(newSize, vector<int>(newSize)),
                        b22(newSize, vector<int>(newSize));

    // Dividir las matrices A y B en submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calcular los productos de Strassen
    vector<vector<int>> m1 = strassen_multiplicacion(sumar_matrices(a11, a22), sumar_matrices(b11, b22));
    vector<vector<int>> m2 = strassen_multiplicacion(sumar_matrices(a21, a22), b11);
    vector<vector<int>> m3 = strassen_multiplicacion(a11, restar_matrices(b12, b22));
    vector<vector<int>> m4 = strassen_multiplicacion(a22, restar_matrices(b21, b11));
    vector<vector<int>> m5 = strassen_multiplicacion(sumar_matrices(a11, a12), b22);
    vector<vector<int>> m6 = strassen_multiplicacion(restar_matrices(a21, a11), sumar_matrices(b11, b12));
    vector<vector<int>> m7 = strassen_multiplicacion(restar_matrices(a12, a22), sumar_matrices(b21, b22));

    // Calcular las submatrices C
    vector<vector<int>> c11 = sumar_matrices(restar_matrices(sumar_matrices(m1, m4), m5), m7);
    vector<vector<int>> c12 = sumar_matrices(m3, m5);
    vector<vector<int>> c21 = sumar_matrices(m2, m4);
    vector<vector<int>> c22 = sumar_matrices(restar_matrices(sumar_matrices(m1, m3), m2), m6);

    // Combinar las submatrices en la matriz C final
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }

    return C;
}
