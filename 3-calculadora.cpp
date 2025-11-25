#include <stdio.h>

int main() {
    int num1, num2, operacion;

    printf("Ingresa el primer numero entero: ");
    scanf("%d", &num1);

    printf("Ingresa el segundo numero entero: ");
    scanf("%d", &num2);

    printf("Selecciona la operacion:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Modulo\n");
    printf("Opcion: ");
    scanf("%d", &operacion);

    switch (operacion) {
        case 1:
            printf("Resultado: %d\n", num1 + num2);
            break;
        case 2:
            printf("Resultado: %d\n", num1 - num2);
            break;
        case 3:
            printf("Resultado: %d\n", num1 * num2);
            break;
        case 4:
            if (num2 != 0) {
                printf("Resultado: %.2f\n", (float)num1 / num2);
            } else {
                printf("Error: division entre cero no permitida\n");
            }
            break;
        case 5:
            if (num2 != 0) {
                printf("Resultado: %d\n", num1 % num2);
            } else {
                printf("Error: modulo entre cero no permitido\n");
            }
            break;
        default:
            printf("Opcion invalida\n");
    }

    return 0;
}
