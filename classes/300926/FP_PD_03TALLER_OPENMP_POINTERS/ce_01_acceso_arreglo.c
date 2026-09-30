/**
 * @file ce_01_acceso_arreglo.c
 * @brief Acceso a elementos de un arreglo con punteros.
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>

#define TAM 10

void llenar(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        *(arr + i) = i + 1;
    }
}

void imprimir(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("*(ptr + %d) = %d\n", i, *(arr + i));
    }
}

int main(void) {
    int arreglo[TAM];
    int *ptr = arreglo;

    llenar(ptr, TAM);
    printf("Valores del arreglo:\n");
    imprimir(ptr, TAM);
    return 0;
}
