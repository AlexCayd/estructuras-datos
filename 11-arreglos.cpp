#include <stdio.h>

int numeros[6];

main() {
    for(int i = 0; i <= 5; i++) {
        printf("\nEscribe el numero %d: ", i+1);
        scanf("%d", &numeros[i]);
    }

    for(int i = 0; i <= 5; i++) {
        printf("\nNúmero [%d]: %d", i+1, numeros[i]);
    }
}