#include <stdio.h>

int potencia(int base, int potencia); 

int main() {
    int base, exponente;
    printf("\nIngresa la base: ");
    scanf("%d", &base);
    printf("\nIngresa la potencia: ");
    scanf("%d", &exponente);

    int resultado = potencia(base, exponente);
    printf("Resultado: %d\n", resultado);
    return 0;
}

int potencia(int base, int potencia) {
    int resultado = 1;
    for (int i = 0; i < potencia; i++) {
        resultado *= base;
    }
    return resultado;
}
