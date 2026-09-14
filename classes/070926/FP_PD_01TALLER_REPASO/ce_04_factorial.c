/**
 * @file ce_04_factorial_paridad.c
 * @brief Calcula el factorial de un numero y verifica si es par o impar.
 * @author Luis Vanegas
 * @date 2026-09-13
 */

#include <stdio.h>
long long factorial(int num) {
    long long rta = 1;
    for (int i = 1; i <= num; i++) {
        rta = rta* i;
    }
    return rta;
}
int esPar(int num) {
    int contador = num;
    int rta = 0;

    while (contador > 0) {
        contador--;
        rta = !rta;
    }
    return rta;
}
int main(void) {
    int num;
    printf("ingresa un numero entero: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("el numero debe ser positivo\n");
        return 1;
    }
    printf("\nel factorial de %d es: %lld\n", num, factorial(num));

    if (esPar(num) == 1) {
        printf("%d es par\n", num);
    } else {
        printf("%d es impar\n", num);
    }
    return 0;
}