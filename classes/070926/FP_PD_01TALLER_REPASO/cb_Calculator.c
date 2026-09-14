/**
 * @file cb_Calculator.c
 * @brief Basic Exercise of calculator in C.
 * @author Luis Vanegas
 * @date 2026-09-07
 */

#include <stdio.h>

int main(void) {
    double num1, num2;
    char op;

    printf("Ingrese operacion (ejemplo: 5 + 3): ");
    
    if (scanf("%lf %c %lf", &num1, &op, &num2) == 3) {
        switch (op) {
            case '+':
                printf("Resultado: %.2f\n", num1 + num2);
                break;
            case '-':
                printf("Resultado: %.2f\n", num1 - num2);
                break;
            case '*':
                printf("Resultado: %.2f\n", num1 * num2);
                break;
            case '/':
                if (num2 != 0) {
                    printf("Resultado: %.2f\n", num1 / num2);
                } else {
                    printf("Error: Division por cero.\n");
                }
                break;
            default:
                printf("Operador no valido.\n");
        }
    }

    return 0;
}
