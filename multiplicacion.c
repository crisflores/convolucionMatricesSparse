#include <stdio.h>
#include <time.h>  // Para medir el tiempo

#define SIZE 32 // Dimensión de las matrices cuadradas

// Función para multiplicar matrices cuadradas de 3x3
void multiply_matrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    // Inicializar la matriz resultado con ceros
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
        }
    }

    // Realizar la multiplicación de las matrices
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para imprimir matrices cuadradas de 3x3
void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Definir las matrices cuadradas A y B
    int A[SIZE][SIZE] = {
        {228,0,0,0,0,0,226,0,0,0,0,0,0,0,0,177,0,0,109,0,0,0,0,0,79,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,122,0,0,219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,205,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63},
        {0,0,0,253,0,0,0,173,0,0,0,248,0,0,208,129,128,0,202,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,126,0,0,0,0,0,0,0,229,0,0,0,0,49,0,0,0,0,0,0,0,0,0,228,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,0,0,0,0,0,108,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,173,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,161,20,228,0,174,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,2,0,0,0,0,184,0,0,0,0,0,130,0,0,0,0,0,0,108,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,125,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,110,0,0},
        {246,0,0,0,0,0,0,0,0,35,0,213,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,167,0,0,35,0,0,203,0,0,0,37,0,0,0,0,0,0,0,0,0,0,0,0,0,110,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,226,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,235,0},
        {0,0,0,0,0,0,7,202,0,0,0,0,0,13,0,0,0,0,110,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,115,0,0,0,0,0,0,0,0,102,0,0,230,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,192,100,0,0,0,0,0,0,0,0,0,0,0,109,0,0,0,0,70,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,151,29,0,0,0,0,0,119,0,0,0,0,0,0,0,51,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,167,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,204,0,0,0,0,77,0,0,0,0,0,0},
        {4,197,0,0,0,207,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,96,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,179,189,0,0,0,0,0,0},
        {0,0,0,0,0,0,39,0,0,0,0,239,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,145,0,0,192,49,0,0,0,0,0,0},
        {196,0,0,0,0,233,0,0,0,0,0,0,0,0,0,0,0,190,0,0,0,0,0,0,0,0,0,96,0,0,0,0},
        {0,0,0,137,0,0,0,0,0,0,247,0,0,0,1,0,0,0,0,0,0,0,91,0,0,0,0,0,0,0,0,0},
        {0,0,0,133,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,116,0,0,208,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,68,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,254,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,84,0,0,0,0,0,0,0,0,0,38,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,177,0,0,0,0,0,0,0,0,0,26,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,44,0,0,0,0,0,38,0,0}
    };

    int B[SIZE][SIZE] = {
        {228,0,0,0,0,0,226,0,0,0,0,0,0,0,0,177,0,0,109,0,0,0,0,0,79,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,122,0,0,219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,205,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63},
        {0,0,0,253,0,0,0,173,0,0,0,248,0,0,208,129,128,0,202,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,126,0,0,0,0,0,0,0,229,0,0,0,0,49,0,0,0,0,0,0,0,0,0,228,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,0,0,0,0,0,108,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,173,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,161,20,228,0,174,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,2,0,0,0,0,184,0,0,0,0,0,130,0,0,0,0,0,0,108,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,125,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,110,0,0},
        {246,0,0,0,0,0,0,0,0,35,0,213,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,101,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,167,0,0,35,0,0,203,0,0,0,37,0,0,0,0,0,0,0,0,0,0,0,0,0,110,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,226,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,235,0},
        {0,0,0,0,0,0,7,202,0,0,0,0,0,13,0,0,0,0,110,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,115,0,0,0,0,0,0,0,0,102,0,0,230,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,192,100,0,0,0,0,0,0,0,0,0,0,0,109,0,0,0,0,70,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,151,29,0,0,0,0,0,119,0,0,0,0,0,0,0,51,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,167,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,204,0,0,0,0,77,0,0,0,0,0,0},
        {4,197,0,0,0,207,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,123,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,96,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,179,189,0,0,0,0,0,0},
        {0,0,0,0,0,0,39,0,0,0,0,239,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,145,0,0,192,49,0,0,0,0,0,0},
        {196,0,0,0,0,233,0,0,0,0,0,0,0,0,0,0,0,190,0,0,0,0,0,0,0,0,0,96,0,0,0,0},
        {0,0,0,137,0,0,0,0,0,0,247,0,0,0,1,0,0,0,0,0,0,0,91,0,0,0,0,0,0,0,0,0},
        {0,0,0,133,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,116,0,0,208,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,68,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,254,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,84,0,0,0,0,0,0,0,0,0,38,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,177,0,0,0,0,0,0,0,0,0,26,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,44,0,0,0,0,0,38,0,0}
    };

    // Matriz para almacenar el resultado
    int C[SIZE][SIZE];

    clock_t start = clock();  // Almacenar el tiempo de inicio

    // Multiplicar las matrices
    multiply_matrices(A, B, C);

    clock_t end = clock();  // Almacenar el tiempo de fin
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;


    // Imprimir las matrices
    //printf("Matriz A:\n");
    //print_matrix(A);

    //printf("\nMatriz B:\n");
    //print_matrix(B);

    printf("\nResultado de A x B:\n");
    print_matrix(C);
    printf("\nTiempo de multiplicación de matrices: %f milisegundos\n", time_taken);
    return 0;
}

