/**
 * @file ce_07_producto_escalar_secuencial.c
 * @brief Producto escalar de dos vectores de tamano N (secuencial).
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 50000000

double productoEscalar(const double *a, const double *b) {
    double producto = 0;
    for (int i = 0; i < N; i++) {
        producto += a[i] * b[i];
    }
    return producto;
}

int main(void) {
    double *a = (double *)malloc(N * sizeof(double));
    double *b = (double *)malloc(N * sizeof(double));

    if (a == NULL || b == NULL) {
        printf("Error al reservar memoria.\n");
        free(a);
        free(b);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        a[i] = (i % 5) + 1;
        b[i] = (i % 3) + 1;
    }

    double startTime = omp_get_wtime();
    double producto = productoEscalar(a, b);
    double elapsedTime = omp_get_wtime() - startTime;

    printf("Producto Escalar (Secuencial): %.0f\n", producto);
    printf("Tiempo Secuencial: %.4f s\n", elapsedTime);

    free(a);
    free(b);
    return 0;
}
