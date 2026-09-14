/**
 * @file ce_03_mayor_menor_ternario.c
 * @brief Determina el mayor y menor de tres numeros usando operadores ternarios.
 * @author Luis Vanegas
 * @date 2026-09-13
 */

#include <stdio.h>
int mayor(int a, int b, int c) {
    int rta;
    rta = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
    return rta;
}

int menor(int a, int b, int c) {
    int rta;
    rta = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
    return rta;
}
int main(void) {
    int num1, num2, num3;

    printf("ingresa el primer numero: ");
    scanf("%d", &num1);
    printf("ingresa el segundo numero: ");
    scanf("%d", &num2);
    printf("ingresa el tercer numero: ");
    scanf("%d", &num3);
    printf("\nEl mayor es: %d\n", mayor(num1, num2, num3));
    printf("El menor es: %d\n", menor(num1, num2, num3));

    return 0;
}