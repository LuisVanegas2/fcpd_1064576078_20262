/**
 * @file ce_07_producto_escalar_paralelo.c
 * @brief Producto escalar de dos vectores con OpenMP, reduction e impresion de hilos.
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 50000000

double productoEscalarParalelo(const double *a, const double *b) {
    double producto = 0;

    #pragma omp parallel for reduction(+:producto)
    for (int i = 0; i < N; i++) {
        producto += a[i] * b[i];
    }

    return producto;
}

void mostrarHilos(void) {
    #pragma omp parallel
    {
        #pragma omp critical
        {
            printf("Hilo %d de %d participando\n", omp_get_thread_num(), omp_get_num_threads());
        }
    }
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
    double producto = productoEscalarParalelo(a, b);
    double elapsedTime = omp_get_wtime() - startTime;

    mostrarHilos();

    printf("Producto Escalar (Paralelo): %.0f\n", producto);
    printf("Tiempo Paralelo: %.4f s\n", elapsedTime);

    free(a);
    free(b);
    return 0;
}
