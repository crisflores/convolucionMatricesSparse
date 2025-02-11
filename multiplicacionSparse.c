#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Para medir el tiempo

#define SIZE 32 // Dimensión de las matrices cuadradas

// Estructura para almacenar tres enteros
typedef struct {
    int values;
    int rowIndices;
    int colOffsets;
} s_nodo;

// Estructura para la lista enlazada
typedef struct t_lista {
    s_nodo s_info;              // Nodo con tres enteros
    struct t_lista* siguiente;  // Puntero al siguiente nodo de la lista
} t_lista;

// Declaraciones de funciones
void crear_list(t_lista **lista);
void convertToCSC(int rows, int cols, int matrix[rows][cols], t_lista **lista);
void poner_lista_ordenada(t_lista **lista, s_nodo *nodo);
void imprimir_lista(t_lista *lista);
void multiplicar(int rows, int cols, t_lista ** lista, int B[SIZE][SIZE], t_lista ** listaC);
int sacar_de_lista(t_lista **lista, s_nodo *nodo);

int main() {
    // Ejemplo de matriz de entrada
    int matrix[SIZE][SIZE] = {
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

    t_lista *listaC;

    t_lista *lista;

    crear_list(&lista);
    crear_list(&listaC);
    
    
    // Convertir la matriz al formato CSC (por columnas)
    convertToCSC(SIZE, SIZE, matrix, &lista);
    //imprimir_lista(lista);

    clock_t start = clock();  // Almacenar el tiempo de inicio

    multiplicar(SIZE, SIZE, &lista, B, &listaC);

    clock_t end = clock();  // Almacenar el tiempo de fin
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000 ;  // Calcular el tiempo transcurrido en segundos


    // Imprimir los resultados
    //printf("Matriz en formato CSC (Lista enlazada ordenada por filas):\n");
    imprimir_lista(listaC);
    printf("\nTiempo de multiplicación de matrices: %f milisegundos\n", time_taken);

    return 0;
}

// Inicializar la lista
void crear_list(t_lista **lista) {
    *lista = NULL;
}

// Convertir la matriz al formato CSC
void convertToCSC(int rows, int cols, int matrix[rows][cols], t_lista **lista) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                s_nodo nodo = {matrix[i][j], i, j};
                poner_lista_ordenada(lista, &nodo);
            }
        }
    }
}

// Imprimir la lista enlazada
void imprimir_lista(t_lista *lista) {
    t_lista *actual = lista;
    while (actual != NULL) {
        printf("Value: %d, Row: %d, Col: %d\n", actual->s_info.values, actual->s_info.rowIndices, actual->s_info.colOffsets);
        actual = actual->siguiente;
    }
}

void multiplicar(int rows, int cols, t_lista ** lista, int B[SIZE][SIZE], t_lista ** listaC){
    s_nodo nodo;
    while(sacar_de_lista(lista, &nodo)){
        for (int k = 0; k < cols; k++){
            if (B[nodo.colOffsets][k] != 0){
                s_nodo nodoC = {nodo.values * B[nodo.colOffsets][k], nodo.rowIndices, k};
                poner_lista_ordenada(listaC, &nodoC);
            }
        }
    }
}


int sacar_de_lista(t_lista **lista, s_nodo *nodo) {
    // Verificar si la lista está vacía
    if (*lista == NULL)
        return 0;

    t_lista *temp = *lista;

    // Copiar la información del primer nodo al nodo proporcionado
    *nodo = temp->s_info;
    // Avanzar el puntero de la lista al siguiente elemento
    *lista = temp->siguiente;

    // Liberar la memoria del nodo extraído
    free(temp);
    return 1;
}

void poner_lista_ordenada(t_lista **lista, s_nodo *nodo) {
    // Si la lista está vacía o el nuevo nodo debe ir al inicio
    if (*lista == NULL || (*lista)->s_info.rowIndices > nodo->rowIndices || ((*lista)->s_info.rowIndices == nodo->rowIndices && (*lista)->s_info.colOffsets > nodo->colOffsets)) {
        
        // Crear un nuevo nodo para la lista
        t_lista *nuevoNodo = (t_lista *)malloc(sizeof(t_lista));
        if (nuevoNodo == NULL) {
            printf("Error al asignar memoria para el nodo.\n");
            exit(1);
        }

        // Copiar los datos del nodo proporcionado al nuevo nodo
        nuevoNodo->s_info = *nodo;
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
    } else {
        // Encontrar la posición donde insertar o acumular el nodo
        t_lista *actual = *lista;
        t_lista *anterior = NULL;

        while (actual != NULL && (actual->s_info.rowIndices < nodo->rowIndices || (actual->s_info.rowIndices == nodo->rowIndices && actual->s_info.colOffsets < nodo->colOffsets))) {
            anterior = actual;
            actual = actual->siguiente;
        }

        // Si encontramos un nodo con la misma fila y columna, acumulamos el valor
        if (actual != NULL && actual->s_info.rowIndices == nodo->rowIndices && actual->s_info.colOffsets == nodo->colOffsets) {
            actual->s_info.values += nodo->values;
        } else {
            // Crear un nuevo nodo e insertarlo en la posición correspondiente
            t_lista *nuevoNodo = (t_lista *)malloc(sizeof(t_lista));
            if (nuevoNodo == NULL) {
                printf("Error al asignar memoria para el nodo.\n");
                exit(1);
            }

            nuevoNodo->s_info = *nodo;
            nuevoNodo->siguiente = actual;
            if (anterior != NULL) {
                anterior->siguiente = nuevoNodo;
            } else {
                *lista = nuevoNodo;
            }
        }
    }
}
