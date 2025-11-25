#include <stdio.h>

void potencia(int base, int exponente); 

int main() {
    int base, exponente;
    printf("\nIngresa la base: ");
    scanf("%d", &base);
    printf("\nIngresa la potencia: ");
    scanf("%d", &exponente);

    potencia(base, exponente); // No guarda nada, solo imprime
    return 0;
}

void potencia(int base, int exponente) {
    int resultado = 1;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    printf("Resultado: %d\n", resultado);
}
