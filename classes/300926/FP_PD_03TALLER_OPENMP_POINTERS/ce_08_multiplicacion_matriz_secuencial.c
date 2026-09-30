/**
 * @file ce_08_multiplicacion_matriz_secuencial.c
 * @brief Multiplicacion secuencial de dos matrices cuadradas N x N.
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000

void multiplicarMatrices(const double *A, const double *B, double *C) {
    for (int i = 0; i < N; i++) {
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
    double *A = (double *)malloc(N * N * sizeof(double));
    double *B = (double *)malloc(N * N * sizeof(double));
    double *C = (double *)malloc(N * N * sizeof(double));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Error al reservar memoria.\n");
        free(A);
        free(B);
        free(C);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i * N + j] = (i + j) % 10;
            B[i * N + j] = (i * j) % 10;
        }
    }

    double startTime = omp_get_wtime();
    multiplicarMatrices(A, B, C);
    double elapsedTime = omp_get_wtime() - startTime;

    double checksum = 0;
    for (int i = 0; i < N * N; i++) {
        checksum += C[i];
    }

    printf("Checksum: %.0f\n", checksum);
    printf("Tiempo Secuencial: %.4f s\n", elapsedTime);

    free(A);
    free(B);
    free(C);
    return 0;
}
