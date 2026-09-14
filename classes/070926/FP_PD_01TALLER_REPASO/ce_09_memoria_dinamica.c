/**
 * @file ce_09_memoria_dinamica_arreglos.c
 * @brief Crea un arreglo dinamico, lo llena con valores del usuario y calcula su suma.
 * @author Luis Vanegas
 * @date 2026-09-13
 */
#include <stdio.h>
#include <stdlib.h>
int sumarArreglo(int *arr, int n) {
    int rta = 0;
    for (int i = 0; i < n; i++) {
        rta = rta + arr[i];
    }
    return rta;
}
int main(void) {
    int n, i;
    int *arreglo;
    printf("ingresa la cantidad de elementos: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("cantidad invalida\n");
        return 1;
    }
    arreglo = (int *)malloc(n * sizeof(int));
    if (arreglo == NULL) {
        printf("no se pudo reservar memoria\n");
        return 1;
    }
    printf("ingresa los %d valores:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }
    printf("\nla suma total es: %d\n", sumarArreglo(arreglo, n));
    free(arreglo);
    return 0;
}