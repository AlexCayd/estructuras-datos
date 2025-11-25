#include <stdio.h>

int main() {
    int num, suma = 0;

    for (int i = 1; i <= 5; i++) {
        printf("\nIngresa el numero %d: ", i);
        scanf("%d", &num);

        if (num % 2 == 0) {
            suma += num;
        }
    }

    printf("\nLa suma de los pares es: %d\n", suma);

    return 0;
}
