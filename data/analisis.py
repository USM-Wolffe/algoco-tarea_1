import matplotlib.pyplot as plt

# Datos de tiempos para listas aleatorias
algoritmos = ['Selection Sort', 'QuickSort', 'MergeSort', 'Sort menor a mayor', 'Sort mayor a menor']
tamanos = [10000, 100000, 500000, 1000000]

# Tiempos de ejecución en ms
tiempos_aleatoria = {
    'Selection Sort': [231, 22353, 573089, 2261891],
    'QuickSort': [2, 25, 139, 294],
    'MergeSort': [3, 40, 223, 432],
    'Sort menor a mayor': [5, 67, 334, 693],
    'Sort mayor a menor': [6, 77, 386, 771]
}

# Crear el gráfico
plt.figure(figsize=(10, 6))
for alg in algoritmos:
    plt.plot(tamanos, tiempos_aleatoria[alg], marker='o', label=alg)

plt.xscale('log')
plt.yscale('log')
plt.xlabel('Tamaño de la lista')
plt.ylabel('Tiempo de ejecución (ms)')
plt.title('Comparación de algoritmos de ordenamiento en listas aleatorias')
plt.legend()
plt.grid(True, which="both", linestyle="--")
plt.tight_layout()

# Guardar el gráfico como imagen
plt.savefig("grafico_algoritmos_ordenamiento.png")
plt.show()

# Datos de tiempos para la multiplicación de matrices
algoritmos_matrices = ['Multiplicación Tradicional', 'Multiplicación Optimizada', 'Strassen']
dimensiones = [25, 100, 500]

# Tiempos de ejecución en milisegundos para cada algoritmo y tamaño de matriz
tiempos_matrices = {
    'Multiplicación Tradicional': [0, 33, 3622],
    'Multiplicación Optimizada': [0, 32, 3366],
    'Strassen': [16, 631, 31487]
}

# Crear gráfico comparativo para la multiplicación de matrices
plt.figure(figsize=(10, 6))
for alg in algoritmos_matrices:
    plt.plot(dimensiones, tiempos_matrices[alg], marker='o', label=alg)

# Configurar gráfico con escalas logarítmicas
plt.xscale('log')
plt.yscale('log')
plt.xlabel('Dimensión de la matriz')
plt.ylabel('Tiempo de ejecución (ms)')
plt.title('Comparación de algoritmos de multiplicación de matrices')
plt.legend()
plt.grid(True, which="both", linestyle="--")
plt.tight_layout()

# Guardar el gráfico como imagen
plt.savefig("grafico_algoritmos_matrices.png")
plt.show()

# Datos de tiempos para listas parcialmente ordenadas (en ms)
algoritmos = ['Selection Sort', 'QuickSort', 'MergeSort', 'Sort menor a mayor', 'Sort mayor a menor']
tamanos = [10000, 100000, 500000]

tiempos_parcialmente_ordenada = {
    'Selection Sort': [230, 22349, 566147],
    'QuickSort': [2, 26, 148],
    'MergeSort': [2, 34, 172],
    'Sort menor a mayor': [4, 60, 311],
    'Sort mayor a menor': [5, 63, 347]
}

# Crear gráfico comparativo para listas parcialmente ordenadas
plt.figure(figsize=(10, 6))
for alg in algoritmos:
    plt.plot(tamanos, tiempos_parcialmente_ordenada[alg], marker='o', label=alg)

# Configuraciones del gráfico
plt.xscale('log')
plt.yscale('log')
plt.xlabel('Tamaño de la lista')
plt.ylabel('Tiempo de ejecución (ms)')
plt.title('Comparación de algoritmos de ordenamiento en listas parcialmente ordenadas')
plt.legend()
plt.grid(True, which="both", linestyle="--")
plt.tight_layout()

# Guardar el gráfico como imagen
plt.savefig("grafico_ordenamiento_parcialmente_ordenadas.png")
plt.show()

# Datos de tiempos para listas inversamente ordenadas (en ms)
algoritmos = ['Selection Sort', 'QuickSort', 'MergeSort', 'Sort menor a mayor', 'Sort mayor a menor']
tamanos = [10000, 100000, 500000]

tiempos_inversamente_ordenada = {
    'Selection Sort': [226, 23119, 773369],
    'QuickSort': [280, 27069, 145],
    'MergeSort': [2, 30, 173],
    'Sort menor a mayor': [2, 29, 314],
    'Sort mayor a menor': [3, 44, 347]
}

# Crear gráfico comparativo para listas inversamente ordenadas
plt.figure(figsize=(10, 6))
for alg in algoritmos:
    plt.plot(tamanos, tiempos_inversamente_ordenada[alg], marker='o', label=alg)

# Configurar el gráfico
plt.xscale('log')
plt.yscale('log')
plt.xlabel('Tamaño de la lista')
plt.ylabel('Tiempo de ejecución (ms)')
plt.title('Comparación de algoritmos de ordenamiento en listas inversamente ordenadas')
plt.legend()
plt.grid(True, which="both", linestyle="--")
plt.tight_layout()

# Guardar el gráfico como imagen
plt.savefig("grafico_ordenamiento_inversamente_ordenadas.png")
plt.show()
