/**
 * @file ce_05_recursividad_suma_digitos.c
 * @brief Suma los digitos de un numero usando recursividad.
 * @author Luis Vanegas
 * @date 2026-09-13
 */
#include <stdio.h>

int sumaDigitos(int num) {
    int rta;
    if (num == 0) {
        return 0;
    }
    rta = (num % 10) + sumaDigitos(num / 10);
    return rta;
}
int main(void) {
    int num;
    printf("ingresa un numero: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("el numero debe ser positivo\n");
        return 1;
    }
    printf("\nla suma de los digitos de %d es: %d\n", num, sumaDigitos(num));
    return 0;
}