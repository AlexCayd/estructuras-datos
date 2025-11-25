#include <stdio.h>

struct alumno {
    int calificaciones[3];     
};

void promedio(int calificaciones[3]) {
    float suma, resultado;

    for (int i = 0; i <= 2; i++) {
        suma =+ calificaciones[i];
    }
    resultado = suma / 3;

    printf("El promedio es: %2.f", resultado);
}

int main() {
    struct alumno a1, a2;

    for(int i = 0; i <= 2; i++) {
        printf("\nIngrese la calificacion [%d] de a1: ");
        scanf("%d", &a1.calificaciones[i]);
    }

    for(int j = 0; j <= 2; j++) {
        printf("\nIngrese la calificacion [%d] de a2: ", j + 1);
        scanf("%d", &a2.calificaciones[j]);
    }

    promedio(a1.calificaciones);
    promedio(a2.calificaciones);

    return 0;
}
