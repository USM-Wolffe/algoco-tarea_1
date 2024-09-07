#include "sorting.h"
#include <bits/stdc++.h>

void ordenar_arr1(vector<int>& arr) {
    sort(arr.begin(), arr.end());  // Ordena el vector de menor a mayor
}

void ordenar_arr_2(vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());  // Ordena el vector de mayor a menor
}
