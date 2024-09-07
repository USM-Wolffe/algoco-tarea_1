#include<bits/stdc++.h>
#include<chrono>
#include "src/quicksort.h"
#include "src/mergesort.h"
#include "src/selecsort.h"
#include "src/algoritmos-cubicos.h"
#include "src/strassen.h"
#include "src/sorting.h" 
int contador_pruebas = 1;  // Contador global


using namespace std;

using namespace std::chrono;

// Función para leer un archivo CSV y devolver un vector de enteros
vector<int> leer_lista_csv(const string& filename) {
    vector<int> lista;
    ifstream file(filename);
    string line, value;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            while (getline(ss, value, ',')) {
                lista.push_back(stoi(value));
            }
        }
        file.close();
    } else {
        cerr << "No se pudo abrir el archivo " << filename << endl;
    }
    return lista;
}

// Función para convertir std::vector a array
int* convertir_vector_a_array(const vector<int>& vec) {
    int* arr = new int[vec.size()];
    for (size_t i = 0; i < vec.size(); ++i) {
        arr[i] = vec[i];
    }
    return arr;
}

// Función para leer una matriz de un archivo CSV
vector<vector<int>> leer_matriz_csv(const string& filename) {
    vector<vector<int>> matriz;
    ifstream file(filename);
    string line, value;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<int> fila;
            stringstream ss(line);
            while (getline(ss, value, ',')) {
                fila.push_back(stoi(value));
            }
            matriz.push_back(fila);
        }
        file.close();
    } else {
        cerr << "No se pudo abrir el archivo " << filename << endl;
    }
    return matriz;
}

void guardar_resultados_csv(const string& filename, const string& algoritmo, long duracion, int tamano) {
    ofstream file;
    file.open(filename, ios::app); // Abrir en modo append para no sobreescribir
    if (file.is_open()) {
        file << algoritmo << "," << tamano << "," << duracion << " ms" << endl;
        file.close();
    } else {
        cerr << "No se pudo abrir el archivo para guardar los resultados." << endl;
    }
}
void funcionmasinutildelmundo(const string& filename){
    ofstream file;
    file.open(filename, ios::app);
    if(file.is_open()){
        file << "-------------------Prueba "<<contador_pruebas<<"-------------------"<<endl;
         
    }
}




// Función principal
int main() {
    funcionmasinutildelmundo("resultados_algoritmos.csv");
    contador_pruebas++;
    vector<int> lista = leer_lista_csv("data/lista_aleatoria_10**6.csv");

    // Prueba de Selection Sort
    int* copia_lista = new int[lista.size()];
    copy(lista.begin(), lista.end(), copia_lista);
    auto inicio1 = high_resolution_clock::now();
    selectionSort(copia_lista, lista.size());
    auto fin1 = high_resolution_clock::now();
    auto duracion1 = duration_cast<milliseconds>(fin1 - inicio1).count();
    cout << "Selection Sort: " << duracion1 << " ms" << endl;
    guardar_resultados_csv("resultados_algoritmos.csv", "Selection Sort", duracion1, lista.size());
    delete[] copia_lista;

    // Prueba de Quicksort
    copia_lista = new int[lista.size()];
    copy(lista.begin(), lista.end(), copia_lista);
    auto inicio2 = high_resolution_clock::now();
    quicksort(copia_lista, 0, lista.size() - 1);
    auto fin2 = high_resolution_clock::now();
    auto duracion2 = duration_cast<milliseconds>(fin2 - inicio2).count();
    cout << "Quicksort: " << duracion2 << " ms" << endl;
    guardar_resultados_csv("resultados_algoritmos.csv", "Quicksort", duracion2, lista.size());
    delete[] copia_lista;

    // Prueba de Mergesort
    copia_lista = new int[lista.size()];
    copy(lista.begin(), lista.end(), copia_lista);
    auto inicio3 = high_resolution_clock::now();
    mergeSort(copia_lista, 0, lista.size() - 1);
    auto fin3 = high_resolution_clock::now();
    auto duracion3 = duration_cast<milliseconds>(fin3 - inicio3).count();
    cout << "Mergesort: " << duracion3 << " ms" << endl;
    guardar_resultados_csv("resultados_algoritmos.csv", "Mergesort", duracion3, lista.size());
    delete[] copia_lista;

    // Prueba de std::sort de menor a mayor
    vector<int> copia_lista_vector = lista;
    auto inicio4 = high_resolution_clock::now();
    ordenar_arr1(copia_lista_vector);
    auto fin4 = high_resolution_clock::now();
    auto duracion4 = duration_cast<milliseconds>(fin4 - inicio4).count();
    cout << "Sorting menor a mayor: " << duracion4 << " ms" << endl;
    guardar_resultados_csv("resultados_algoritmos.csv", "Sort de menor a mayor", duracion4,lista.size());

    // Prueba de std::sort de mayor a menor
    copia_lista_vector = lista;
    auto inicio5 = high_resolution_clock::now();
    ordenar_arr_2(copia_lista_vector);
    auto fin5 = high_resolution_clock::now();
    auto duracion5 = duration_cast<milliseconds>(fin5 - inicio5).count();
    cout << "Sorting mayor a menor: " << duracion5 << " ms" << endl;
    guardar_resultados_csv("resultados_algoritmos.csv", "Sort de mayor a menor", duracion5, lista.size());

    // Prueba de multiplicación de matrices tradicional
    vector<vector<int>> A = leer_matriz_csv("data/matriz_aleatoria.csv");
    vector<vector<int>> B = leer_matriz_csv("data/matriz_aleatoria.csv");
    auto inicio6 = high_resolution_clock::now();
    vector<vector<int>> C = multiplicacion_tradicional(A, B);
    auto fin6 = high_resolution_clock::now();
    auto duracion6 = duration_cast<milliseconds>(fin6 - inicio6).count();
    cout << "Multiplicación tradicional: " << duracion6 << " ms" << endl;
    guardar_resultados_csv("resultados_algoritmos.csv", "Multiplicación tradicional", duracion6, A.size());

    // Prueba de multiplicación optimizada
    inicio6 = high_resolution_clock::now();
    C = multiplicacion_optimizada(A, B);
    fin6 = high_resolution_clock::now();
    duracion6 = duration_cast<milliseconds>(fin6 - inicio6).count();
    cout << "Multiplicación optimizada: " << duracion6 << " ms" << endl;
    guardar_resultados_csv("resultados_algoritmos.csv", "Multiplicación optimizada", duracion6, A.size());
    // Prueba de Strassen
    auto inicio7 = high_resolution_clock::now();
    C = strassen_multiplicacion(A, B);
    auto fin7 = high_resolution_clock::now();
    auto duracion7 = duration_cast<milliseconds>(fin7 - inicio7).count();
    cout << "Multiplicación Strassen: " << duracion7 << " ms" << endl;
    guardar_resultados_csv("resultados_algoritmos.csv", "Multiplicación Strassen", duracion7, A.size());

    return 0;
}