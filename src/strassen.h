#ifndef STRASSEN_H
#define STRASSEN_H

#include <vector>

using namespace std;

vector<vector<int>> strassen_multiplicacion(const vector<vector<int>>& A, const vector<vector<int>>& B);
vector<vector<int>> sumar_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B);
vector<vector<int>> restar_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B);

#endif
