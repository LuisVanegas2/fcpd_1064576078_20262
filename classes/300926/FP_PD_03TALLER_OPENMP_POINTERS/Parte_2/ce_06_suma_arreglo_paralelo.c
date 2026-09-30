/**
 * @file ce_06_suma_arreglo_paralelo.c
 * @brief Suma paralela de un arreglo usando OpenMP con reduction(+:suma).
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 200000000

long long sumaArregloParalelo(const int *arreglo) {
    long long suma = 0;

    #pragma omp parallel for reduction(+:suma)
    for (int i = 0; i < N; i++) {
        suma += arreglo[i];
    }

    return suma;
}

int main(void) {
    int *arreglo = (int *)malloc(N * sizeof(int));
    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        arreglo[i] = (i % 10) + 1;
    }

    double startTime = omp_get_wtime();
    long long suma = sumaArregloParalelo(arreglo);
    double elapsedTime = omp_get_wtime() - startTime;

    printf("Suma (Paralelo): %lld\n", suma);
    printf("Tiempo Paralelo: %.4f s\n", elapsedTime);

    free(arreglo);
    return 0;
}
