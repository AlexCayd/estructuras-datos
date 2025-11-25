#include <stdio.h>

int main() {
    int puntaje, beca = 0;
    float promedio;

    printf("\nIngresa el puntaje: ");
    scanf("%d", &puntaje);
    printf("\nIngresa el promedio: ");
    scanf("%f", &promedio);

    switch (puntaje) {
        case 100:
            if (promedio == 8.6f) {
                beca = 90;
                break;
            } else if (promedio <= 8.0f) {
                beca = 60;
                break;
            }
            break;

        case 200:
            if (promedio >= 9.0f) {
                beca = 70;
                break;
            } else {
                beca = 50;
                break;
            }

        case 300:
            if (promedio == 10.0f) {
                beca = 70;
            }
            break;

        default:
            printf("\nOpcion no valida");
            break;
    }

    printf("\nLa beca es: %d%%", beca);
    return 0;
}
