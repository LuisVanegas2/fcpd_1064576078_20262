/**
 * @file ce_03_matriz_punteros.c
 * @brief Matriz de 3x3 usando int **matriz, memoria dinamica y aritmetica de punteros.
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLS 3

int **crear_matriz(int filas, int cols) {
    int **matriz = (int **)malloc(filas * sizeof(int *));
    int i, j;

    if (matriz == NULL) {
        return NULL;
    }

    for (i = 0; i < filas; i++) {
        *(matriz + i) = (int *)malloc(cols * sizeof(int));
        if (*(matriz + i) == NULL) {
            for (j = 0; j < i; j++) {
                free(*(matriz + j));
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

void inicializar(int **matriz, int filas, int cols) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            *(*(matriz + i) + j) = i * cols + j + 1;
        }
    }
}

void imprimir(int **matriz, int filas, int cols) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

void liberar(int **matriz, int filas) {
    int i;
    for (i = 0; i < filas; i++) {
        free(*(matriz + i));
    }
    free(matriz);
}

int main(void) {
    int **matriz = crear_matriz(FILAS, COLS);
    if (matriz == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    inicializar(matriz, FILAS, COLS);
    printf("Matriz:\n");
    imprimir(matriz, FILAS, COLS);
    liberar(matriz, FILAS);
    return 0;
}
