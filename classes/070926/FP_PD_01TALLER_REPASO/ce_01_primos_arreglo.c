/**
 * @file ce_01_primos_arreglo.c
 * @brief Genera un arreglo de numeros aleatorios y cuenta cuantos son primos.
 * @author Luis Vanegas
 * @date 2026-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX 100

int esPrimo(int num) {
    int primo = 1;

    if (num < 2) {
        primo = 0;
    }

    for (int j = 2; j < num; j++) {
        if (num % j == 0) {
            primo = 0;
            break;
        }
    }
    return primo;
}
int main(void) {
    int n, i;
    int arreglo[TAM_MAX];
    int rta = 0;
    srand(time(NULL));
    printf("ingresa el tamano del arreglo: ");
    scanf("%d", &n);
    if (n <= 0 || n > TAM_MAX) {
        printf("tamaño invalido\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        arreglo[i] = (rand() % 99) + 2;
    }

    printf("arreglo: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        if (esPrimo(arreglo[i]) == 1) {
            rta++;
        }
    }
    printf("numeros primos encontrados: %d\n", rta);
    return 0;
}