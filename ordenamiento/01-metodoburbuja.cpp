#include <stdio.h>

int main() {
    int numeros[] = {32, 5, 44, 100, 18};
    int i, j, aux;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(numeros[j] > numeros[j+1]) {
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }

    printf("Orden ascendente: ");
    for(i = 0; i < 5 ; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}