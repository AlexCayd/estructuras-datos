#include <stdio.h>

int main() {
    int gastos = 1, gastosMayores, monto;
    printf("\nEscribe el monto 0 si quieres terminar el programa");

    do {
        printf("\nEl gasto %d fue de: ", gastos);
        scanf("%d", &monto);
        
        if(monto != 0) {
            gastos++;
        }
    } while (monto != 0);
    
    printf("Número de gastos: %d", gastos);
    return 0;

}