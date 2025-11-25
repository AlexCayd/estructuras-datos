#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Ingresa el primer numero: ");
    scanf("%d", &num1);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &num2);

    printf("Ingresa el tercer numero: ");
    scanf("%d", &num3);

    if (num1 >= num2 && num1 >= num3) {
        printf("El mayor es: %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("El mayor es: %d\n", num2);
    } else {
        printf("El mayor es: %d\n", num3);
    }

    return 0;
}