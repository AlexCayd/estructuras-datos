#include <stdio.h>
#include <string.h>

struct datos {
    char cliente[30];
    int cuenta;
    double cantidad;
};

int main(void) {
    struct datos registro;
    struct datos *q = &registro;

    strcpy(q->cliente, "Alfredo");
    q->cuenta = 12;
    q->cantidad = 23917.33;

    printf("Inicial:\n%s\n%d\n%.2f\n\n", q->cliente, q->cuenta, q->cantidad);

    printf("Dame el nombre del cliente (sin espacios): ");
    scanf("%s", q->cliente);

    printf("Dame el número de cuenta: ");
    scanf("%d", &q->cuenta);

    printf("Dame la cantidad: ");
    scanf("%lf", &q->cantidad);           

    printf("\nRegistro:\n");
    printf("Cliente : %s\n", q->cliente);
    printf("Cuenta  : %d\n", q->cuenta);
    printf("Cantidad: %.2f\n", q->cantidad);

    return 0;
}
