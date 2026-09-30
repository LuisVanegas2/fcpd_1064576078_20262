/**
 * @file ce_04_intercambio.c
 * @brief Intercambio de valores entre dos variables usando la funcion swap con punteros.
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x, y;

    printf("Ingresa 2 numeros: ");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Antes del swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Despues del swap: x = %d, y = %d\n", x, y);
    return 0;
}
