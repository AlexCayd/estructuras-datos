#include <stdio.h>

int main() {
    int num1, num2;

    printf("Ingresa el primer numero:\n");
    scanf("%d", &num1);
    printf("Ingresa el segundo numero:\n");
    scanf("%d", &num2);


    if (num1 > num2) {
        printf("El mayor es: %d\n", num1);
    } else if (num2 > num1) {
        printf("El mayor es: %d\n", num2);
    } else {
        printf("Ambos numeros son iguales\n");
    }

    return 0;
}
