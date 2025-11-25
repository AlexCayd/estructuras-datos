#include <stdio.h>

float avg(float num1, float num2) {
    float resultado;
    resultado = num1 + num2;
    resultado = resultado/2;
    return(resultado);
}

main() {
    float x, y, promedio;
    x = 10;
    y = 20;
    promedio = avg(x, y);
    printf("El promedio es %f\n", promedio);
}