import pandas as pd
import matplotlib.pyplot as plt

# Leer los resultados desde el archivo CSV
df = pd.read_csv("resultados_algoritmos.csv", names=["Algoritmo", "Tamaño", "Tiempo", "Prueba"])

# Limpiar la columna "Tiempo" (eliminar " ms" y convertir a números)
df["Tiempo"] = df["Tiempo"].str.replace(" ms", "").astype(float)

# Dividir el dataframe en ordenamiento y multiplicación de matrices
df_ordenamiento = df[df["Algoritmo"].str.contains("Sort|Sorting")]
df_multiplicacion = df[df["Algoritmo"].str.contains("Multiplicación")]

# Gráfico 1: Tiempos de ejecución para algoritmos de ordenamiento
plt.figure(figsize=(10, 6))
for algoritmo in df_ordenamiento["Algoritmo"].unique():
    subset = df_ordenamiento[df_ordenamiento["Algoritmo"] == algoritmo]
    plt.plot(subset["Tamaño"], subset["Tiempo"], label=algoritmo)

plt.xlabel("Tamaño de la muestra")
plt.ylabel("Tiempo de ejecución (ms)")
plt.title("Tiempos de ejecución por algoritmo de ordenamiento")
plt.legend()
plt.grid(True)
plt.yscale("log")  # Escala logarítmica
plt.show()

# Gráfico 2: Tiempos de ejecución para algoritmos de multiplicación de matrices
plt.figure(figsize=(10, 6))
for algoritmo in df_multiplicacion["Algoritmo"].unique():
    subset = df_multiplicacion[df_multiplicacion["Algoritmo"] == algoritmo]
    plt.plot(subset["Tamaño"], subset["Tiempo"], label=algoritmo)

plt.xlabel("Tamaño de la matriz")
plt.ylabel("Tiempo de ejecución (ms)")
plt.title("Tiempos de ejecución por algoritmo de multiplicación de matrices")
plt.legend()
plt.grid(True)
plt.yscale("log")  # Escala logarítmica
plt.show()