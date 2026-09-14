/**
 * @file ce_07_matriz_diagonales.c
 * @brief Crea una matriz cuadrada con numeros aleatorios y compara sus diagonales.
 * @author Luis Vanegas
 * @date 2026-09-13
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX 10
void llenarMatriz(int matriz[TAM_MAX][TAM_MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = (rand() % 50) + 1;
        }
    }
}
void sumarDiagonales(int matriz[TAM_MAX][TAM_MAX], int n, int *ppal, int *sec) {
    *ppal = 0;
    *sec = 0;
    for (int i = 0; i < n; i++) {
        *ppal = *ppal + matriz[i][i];
        *sec = *sec + matriz[i][n - 1 - i];
    }
}
int main(void) {
    int matriz[TAM_MAX][TAM_MAX];
    int n, i, j;
    int diagPpal, diagSec;
    srand(time(NULL));
    printf("ingresa el tamaño de la matriz: ");
    scanf("%d", &n);

    if (n <= 0 || n > TAM_MAX) {
        printf("tamaño invalido\n");
        return 1;
    }
    llenarMatriz(matriz, n);
    printf("\nMatriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    sumarDiagonales(matriz, n, &diagPpal, &diagSec);
    printf("\nsuma diagonal principal: %d\n", diagPpal);
    printf("suma diagonal secundaria: %d\n", diagSec);
    if (diagPpal > diagSec) {
        printf("la diagonal principal es mayor\n");
    } else if (diagSec > diagPpal) {
        printf("la diagonal secundaria es mayor\n");
    } else {
        printf("las dos diagonales son iguales\n");
    }
    return 0;
}