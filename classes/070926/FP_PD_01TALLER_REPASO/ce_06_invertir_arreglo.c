/**
 * @file ce_06_invertir_arreglo_punteros.c
 * @brief Invierte los elementos de un arreglo usando aritmetica de punteros.
 * @author Luis Vanegas
 * @date 2026-09-13
 */
#include <stdio.h>
#define TAM_MAX 100
void invertir(int *arr, int n) {
    int *inicio = arr;
    int *fin = arr + (n - 1);
    int rta;
    while (inicio < fin) {
        rta = *inicio;
        *inicio = *fin;
        *fin = rta;
        inicio++;
        fin--;
    }
}
int main(void) {
    int arreglo[TAM_MAX];
    int n, i;
    printf("ingresa el tamano del arreglo: ");
    scanf("%d", &n);

    if (n <= 0 || n > TAM_MAX) {
        printf("tamaño invalido\n");
        return 1;
    }
    printf("ingresa los %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }
    invertir(arreglo, n);
    printf("\nel arreglo invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
    return 0;
}