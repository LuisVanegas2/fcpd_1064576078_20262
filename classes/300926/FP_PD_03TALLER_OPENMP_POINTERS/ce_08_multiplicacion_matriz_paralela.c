/**
 * @file ce_08_multiplicacion_matriz_paralela.c
 * @brief Multiplicacion paralela de dos matrices cuadradas N x N usando OpenMP parallel for.
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000

void multiplicarMatricesParalelo(const double *A, const double *B, double *C, int *filasPorHilo) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        filasPorHilo[omp_get_thread_num()]++;
        for (int j = 0; j < N; j++) {
            double suma = 0;
            for (int k = 0; k < N; k++) {
                suma += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = suma;
        }
    }
}

int main(void) {
    int hilos = omp_get_max_threads();

    double *A = (double *)malloc(N * N * sizeof(double));
    double *B = (double *)malloc(N * N * sizeof(double));
    double *C = (double *)malloc(N * N * sizeof(double));
    int *filasPorHilo = (int *)calloc(hilos, sizeof(int));

    if (A == NULL || B == NULL || C == NULL || filasPorHilo == NULL) {
        printf("Error al reservar memoria.\n");
        free(A);
        free(B);
        free(C);
        free(filasPorHilo);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i * N + j] = (i + j) % 10;
            B[i * N + j] = (i * j) % 10;
        }
    }

    double startTime = omp_get_wtime();
    multiplicarMatricesParalelo(A, B, C, filasPorHilo);
    double elapsedTime = omp_get_wtime() - startTime;

    for (int t = 0; t < hilos; t++) {
        printf("Hilo %d calculo %d filas\n", t, filasPorHilo[t]);
    }

    double checksum = 0;
    for (int i = 0; i < N * N; i++) {
        checksum += C[i];
    }

    printf("Checksum: %.0f\n", checksum);
    printf("Tiempo Paralelo: %.4f s\n", elapsedTime);

    free(A);
    free(B);
    free(C);
    free(filasPorHilo);
    return 0;
}
