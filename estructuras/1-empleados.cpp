#include <stdio.h>

struct empleado {
    int numero;     
    float salario;
};

int main() {
    struct empleado e1, e2;

    printf("Ingrese el numero de empleado 1: ");
    scanf("%d", &e1.numero);
    printf("Ingrese el salario del empleado 1: ");
    scanf("%f", &e1.salario);

    printf("\nIngrese el numero de empleado 2: ");
    scanf("%d", &e2.numero);
    printf("Ingrese el salario del empleado 2: ");
    scanf("%f", &e2.salario);

    printf("Empleado 1. Numero: %d, Salario: %f\n", e1.numero, e1.salario);
    printf("Empleado 2. Numero: %d, Salario: %f\n", e2.numero, e2.salario);

    return 0;
}
