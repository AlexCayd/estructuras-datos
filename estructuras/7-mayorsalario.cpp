#include <stdio.h>

struct registro {
    int id;
    int edad;
    double sal;
};

void mayorSalario(struct registro *e1, struct registro *e2);

int main() {
    struct registro emp_1, emp_2;   
    struct registro *p1 = &emp_1;   
    struct registro *p2 = &emp_2;   

    printf("Empleado 1:\n");
    printf("ID: ");
    scanf("%d", &p1->id);
    printf("Edad: ");
    scanf("%d", &p1->edad);
    printf("Salario: ");
    scanf("%lf", &p1->sal);

    // Captura de datos empleado 2
    printf("\nEmpleado 2:\n");
    printf("ID: ");
    scanf("%d", &p2->id);
    printf("Edad: ");
    scanf("%d", &p2->edad);
    printf("Salario: ");
    scanf("%lf", &p2->sal);

    mayorSalario(p1, p2);

    return 0;
}

void mayorSalario(struct registro *e1, struct registro *e2) {
    struct registro *mayor;

    if (e1->sal > e2->sal) {
        mayor = e1;
    } else {
        mayor = e2;
    }

    printf("\n=== Empleado con mayor salario ===\n");
    printf("ID: %d\n", mayor->id);
    printf("Edad: %d\n", mayor->edad);
    printf("Salario: %.2f\n", mayor->sal);
}
