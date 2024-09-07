import random
import csv

# Generar lista aleatoria con un rango más amplio
def generar_lista_aleatoria(tamano, min_val=0, max_val=1000000):
    """Genera una lista aleatoria de tamaño `tamano` con un rango amplio de valores."""
    return [random.randint(min_val, max_val) for _ in range(tamano)]

# Generar lista parcialmente ordenada con un rango amplio de valores
def generar_lista_parcialmente_ordenada(tamano, porcentaje_ordenado=0.5, min_val=0, max_val=1000000):
    """Genera una lista parcialmente ordenada en base al porcentaje especificado con un rango amplio de valores."""
    limite = int(tamano * porcentaje_ordenado)
    lista = sorted([random.randint(min_val, max_val) for _ in range(limite)])
    lista.extend([random.randint(min_val, max_val) for _ in range(tamano - limite)])
    return lista

# Generar lista inversamente ordenada con un rango amplio de valores
def generar_lista_inversamente_ordenada(tamano, min_val=0, max_val=1000000):
    """Genera una lista ordenada de manera inversa con un rango amplio de valores."""
    return sorted([random.randint(min_val, max_val) for _ in range(tamano)], reverse=True)

# Guardar listas en archivos CSV
def guardar_lista_csv(lista, filename):
    """Guarda una lista en un archivo CSV."""
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(lista)

# Tamaño grande de las listas (10^5 elementos)
tamano = 500000

# Generar y guardar las listas
lista_aleatoria = generar_lista_aleatoria(tamano)
guardar_lista_csv(lista_aleatoria, 'lista_aleatoria_500000.csv')

lista_parcialmente_ordenada = generar_lista_parcialmente_ordenada(tamano, porcentaje_ordenado=0.5)
guardar_lista_csv(lista_parcialmente_ordenada, 'lista_parcialmente_ordenada_500000.csv')

lista_inversamente_ordenada = generar_lista_inversamente_ordenada(tamano)
guardar_lista_csv(lista_inversamente_ordenada, 'lista_inversamente_ordenada_500000.csv')

print("¡Listas generadas y guardadas en archivos CSV!")


###################################Matrices############################################
# Generar matriz cuadrada aleatoria
def generar_matriz_aleatoria(n, min_val=0, max_val=100):
    """Genera una matriz cuadrada de tamaño `n` con valores aleatorios."""
    return [[random.randint(min_val, max_val) for _ in range(n)] for _ in range(n)]

# Guardar matriz en archivo CSV
def guardar_matriz_csv(matriz, filename):
    """Guarda una matriz en un archivo CSV."""
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(matriz)

# Tamaño de la matriz (ejemplo: 100x100)
tamano_matriz = 500

# Generar y guardar la matriz aleatoria
matriz_aleatoria = generar_matriz_aleatoria(tamano_matriz)
guardar_matriz_csv(matriz_aleatoria, 'matriz_aleatoria_tamano_500.csv')

print("¡Matriz aleatoria generada y guardada en archivo CSV!")