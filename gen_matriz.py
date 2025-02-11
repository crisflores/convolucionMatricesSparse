import numpy as np
from scipy.sparse import random

# Generar la matriz dispersa de 32x32 con densidad de 0.1 y valores enteros entre 0 y 255
sparse_random_matrix = random(32, 32, density=0.1, format='csr', data_rvs=lambda size: np.random.randint(0, 256, size))

# Convertir la matriz dispersa a densa
dense_matrix = sparse_random_matrix.toarray()

# Guardar la matriz densa en un archivo de texto plano con el formato solicitado
with open('sparse_random_matrix_formatted.txt', 'w') as f:
    for row in dense_matrix:
        # Escribir cada fila rodeada por llaves y con valores enteros, separados por comas
        formatted_row = "{" + ",".join([f"{int(val)}" for val in row]) + "}"
        f.write(formatted_row + "\n")

print("Matriz guardada en 'sparse_random_matrix_formatted.txt'")
