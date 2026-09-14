/**
 * @file ce_10_gestion_estudiantes_structs.c
 * @brief Sistema de gestion de estudiantes usando estructuras, punteros y memoria dinamica.
 * @author Luis Vanegas
 * @date 2026-09-13
 */
#include <stdio.h>
#include <stdlib.h>
#define NOTAS 3

struct Estudiante {
    int id;
    char nombre[50];
    float notas[NOTAS];
    float promedio;
};
float calcularPromedio(struct Estudiante *est) {
    float rta = 0;
    for (int i = 0; i < NOTAS; i++) {
        rta = rta + est->notas[i];
    }
    rta = rta / NOTAS;
    return rta;
}
int main(void) {
    int n, i, j;
    struct Estudiante *lista;
    printf("ingresa la cantidad de estudiantes: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("cantidad invalida\n");
        return 1;
    }
    lista = (struct Estudiante *)malloc(n * sizeof(struct Estudiante));
    if (lista == NULL) {
        printf("no se pudo reservar memoria\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("\nestudiante %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &lista[i].id);
        printf("Nombre: ");
        scanf(" %[^\n]", lista[i].nombre);
        for (j = 0; j < NOTAS; j++) {
            printf("nota %d: ", j + 1);
            scanf("%f", &lista[i].notas[j]);
        }
        lista[i].promedio = calcularPromedio(&lista[i]);
    }
    printf("\n--- Promedios ---\n");
    for (i = 0; i < n; i++) {
        printf("%s (ID %d): %.2f\n", lista[i].nombre, lista[i].id, lista[i].promedio);
    }
    printf("\n--- Aprobados ---\n");
    for (i = 0; i < n; i++) {
        if (lista[i].promedio >= 60) {
            printf("%s (ID %d): %.2f\n", lista[i].nombre, lista[i].id, lista[i].promedio);
        }
    }
    free(lista);
    return 0;
}