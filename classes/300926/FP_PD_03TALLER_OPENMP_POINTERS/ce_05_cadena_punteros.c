/**
 * @file ce_05_cadena_punteros.c
 * @brief Recorre una cadena de caracteres usando un puntero, imprimiendo cada caracter y su direccion de memoria.
 * @author Luis Vanegas
 * @date 2026-09-30
 */
#include <stdio.h>

void recorrer(char *cadena) {
    char *ptr = cadena;
    printf("Caracter | Direccion de Memoria\n");
    printf("---------|---------------------\n");

    while (*ptr != '\0') {
        printf("   '%c'   | %p\n", *ptr, (void *)ptr);
        ptr++;
    }
}

int main(void) {
    char cadena[] = "Punteros";

    printf("Cadena: \"%s\"\n\n", cadena);
    recorrer(cadena);
    return 0;
}
