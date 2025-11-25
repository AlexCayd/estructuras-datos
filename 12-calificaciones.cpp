#include <stdio.h>

void promedio(int calificaciones[]);

main() {
    int calificaciones[5];

    for(int i = 0; i <= 4; i++) {
        printf("\nIngresa la calificacion [%d]: ", i+1);
        scanf("%d", &calificaciones[i]);
    }
    promedio(calificaciones);
}

void promedio(int calificaciones[]) {
    int suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += calificaciones[i];
    }
    float prom = suma / 5.0;
    printf("\nEl promedio es: %.2f\n", prom);
}