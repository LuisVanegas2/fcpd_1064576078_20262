/**
 * @file ce_02_intercambio_punteros.c
 * @brief Intercambia los valores de dos enteros usando punteros.
 * @author Luis Vanegas
 * @date 2026-09-13
 */

#include <stdio.h>

void intercambiar(int *ptr1, int *ptr2) {
    int rta;
    if (ptr1 != NULL && ptr2 != NULL) {
        rta = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = rta;
    }
}
int main(void) {
    int num1, num2;
    printf("ingresa el primer numero: ");
    scanf("%d", &num1);

    printf("ingresa el segundo numero: ");
    scanf("%d", &num2);

    printf("\nAntes:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    intercambiar(&num1, &num2);

    printf("\nDespues:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}