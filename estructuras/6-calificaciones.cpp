#include <stdio.h>

#define EQUIPOS 5
#define INTEGRANTES 2
#define EXAMENES 3

// Definición de la estructura
struct Equipo {
    int numeroEquipo;
    int expediente[INTEGRANTES];
    float calificaciones[EXAMENES];
    float promedio;
};

// Prototipo de la función
void mostrarEquipos(struct Equipo equipos[], int n);

int main() {
    struct Equipo equipos[EQUIPOS];

    // Captura de datos
    for (int i = 0; i < EQUIPOS; i++) {
        printf("\n=== Equipo %d ===\n", i + 1);
        equipos[i].numeroEquipo = i + 1;

        // Expedientes
        for (int j = 0; j < INTEGRANTES; j++) {
            printf("Ingrese expediente del integrante %d: ", j + 1);
            scanf("%d", &equipos[i].expediente[j]);
        }

        // Calificaciones
        float suma = 0;
        for (int k = 0; k < EXAMENES; k++) {
            printf("Ingrese calificacion del examen %d: ", k + 1);
            scanf("%f", &equipos[i].calificaciones[k]);
            suma += equipos[i].calificaciones[k];
        }

        // Calcular promedio
        equipos[i].promedio = suma / EXAMENES;
    }

    // Pasar el arreglo a la función
    mostrarEquipos(equipos, EQUIPOS);

    return 0;
}

// Función para mostrar datos
void mostrarEquipos(struct Equipo equipos[], int n) {
    printf("\n=== Resultados ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nEquipo %d\n", equipos[i].numeroEquipo);
        printf("Expedientes: ");
        for (int j = 0; j < INTEGRANTES; j++) {
            printf("%d ", equipos[i].expediente[j]);
        }
        printf("\nCalificaciones: ");
        for (int k = 0; k < EXAMENES; k++) {
            printf("%.2f ", equipos[i].calificaciones[k]);
        }
        printf("\nPromedio: %.2f\n", equipos[i].promedio);
    }
}
