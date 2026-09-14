/**
 * @file ce_08_notas_calificaciones.c
 * @brief Asigna calificacion en letras a partir de una nota numerica entre 0 y 100.
 * @author Luis Vanegas
 * @date 2026-09-13
 */

#include <stdio.h>

int main(void) {
    float nota;

    printf("ingresa la nota (0 - 100): ");
    scanf("%f", &nota);

    if (nota < 0 || nota > 100) {
        printf("nota invalida\n");
        return 1;
    }

    if (nota >= 90) {
        printf("Calificacion: A\n");
    } else if (nota >= 80) {
        printf("Calificacion: B\n");
    } else if (nota >= 70) {
        printf("Calificacion: C\n");
    } else if (nota >= 60) {
        printf("Calificacion: D\n");
    } else {
        printf("Calificacion: F\n");
    }

    return 0;
}
