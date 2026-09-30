/**
 * @file ce_02_suma_arreglo.c
 * @brief Suma de elementos de un arreglo usando punteros.
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>

#define TAM_MAX 100

void leer(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
}

int sumar(int *arr, int n) {
    int *fin = arr + n;
    int suma = 0;

    while (arr < fin) {
        suma += *arr;
        arr++;
    }
    return suma;
}

int main(void) {
    int arreglo[TAM_MAX];
    int n;

    printf("Ingresa el tamano del arreglo: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > TAM_MAX) {
        printf("Tamano invalido.\n");
        return 1;
    }

    printf("Ingresa los %d numeros:\n", n);
    leer(arreglo, n);
    printf("La suma de los elementos es: %d\n", sumar(arreglo, n));
    return 0;
}
