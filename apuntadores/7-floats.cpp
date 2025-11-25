#include <stdio.h>

void multiplicar(float *num1, float *num2) {
    float resultado;
    resultado = (*num1) * (*num2);
    printf("Resultado: %.2f\n", resultado);
}

int main() {
    float num1, *apun1, num2, *apun2;

    printf("\nIngresa dos numeros: ");
    scanf("%f %f", &num1, &num2);

    multiplicar(&num1, &num2);   
    return 0;
}
