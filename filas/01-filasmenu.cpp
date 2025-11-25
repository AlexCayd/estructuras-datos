#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct fila {
    int front;
    int rear;
    int elementos[MAX];
};

void inicializar(struct fila *f) {
    f->front = 0;
    f->rear = -1;
}

int estaVacia(struct fila *f) {
    return f->rear < f->front;
}

int estaLlena(struct fila *f) {
    return f->rear == MAX - 1;
}

void insertar(struct fila *f, int valor) {
    if (estaLlena(f)) {
        printf("La fila esta llena\n");
        return;
    }
    f->rear++;
    f->elementos[f->rear] = valor;
}

void remover(struct fila *f) {
    if (estaVacia(f)) {
        printf("La fila esta vacia\n");
        return;
    }
    printf("Se removio el elemento: %d\n", f->elementos[f->front]);
    f->front++;
}

void imprimir(struct fila *f) {
    if (estaVacia(f)) {
        printf("Vacio\n");
        return;
    }
    for (int i = f->front; i <= f->rear; i++) {
        printf("%d ", f->elementos[i]);
    }
    printf("\n");
}

int sacarAuto(struct fila *f, int placa) {
    if (estaVacia(f)) {
        printf("El estacionamiento esta vacio\n");
        return 0;
    }

    int encontrado = 0;
    int posicion = -1;
    
    // Buscar la posición del auto
    for (int i = f->front; i <= f->rear; i++) {
        if (f->elementos[i] == placa) {
            encontrado = 1;
            posicion = i;
            break;
        }
    }
    
    if (!encontrado) {
        printf("  -> El auto con placa %d no esta en el estacionamiento\n", placa);
        return 0;
    }
    
    printf("  -> Salio el auto con placa %d\n", placa);
    
    // Desplazar todos los elementos hacia adelante para llenar el hueco
    for (int i = posicion; i < f->rear; i++) {
        f->elementos[i] = f->elementos[i + 1];
    }
    
    // Decrementar rear porque ahora hay un elemento menos
    f->rear--;
    
    return encontrado;
}

void estacionamiento(struct fila *f) {
    inicializar(f);
    
    printf("\n=== SISTEMA DE ESTACIONAMIENTO ===\n");
    printf("MAX %d espacios disponibles\n\n", MAX);
    
    char continuar = 's';
    
    while (continuar == 's' || continuar == 'S') {
        printf("\nOpciones:\n");
        printf("1. Entrar auto(s)\n");
        printf("2. Sacar auto\n");
        printf("3. Ver estado\n");
        printf("4. Terminar\n");
        printf("Seleccione opcion: ");
        
        int opcion;
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1: {
                printf("Cuantos autos van a entrar? ");
                int cantidad;
                scanf("%d", &cantidad);
                
                printf("Ingrese las placas:\n");
                for (int i = 0; i < cantidad; i++) {
                    int placa;
                    scanf("%d", &placa);
                    if (!estaLlena(f)) {
                        insertar(f, placa);
                        printf("  -> Entro el auto con placa %d\n", placa);
                    } else {
                        printf("  -> No hay espacio para el auto %d (overflow)\n", placa);
                    }
                }
                printf("\nEstado actual: ");
                imprimir(f);
                break;
            }
            case 2: {
                printf("Ingrese la placa del auto a sacar: ");
                int placa;
                scanf("%d", &placa);
                sacarAuto(f, placa);
                printf("\nEstado actual: ");
                imprimir(f);
                break;
            }
            case 3:
                printf("\nEstado actual: ");
                imprimir(f);
                break;
            case 4:
                continuar = 'n';
                printf("\nSaliendo del sistema de estacionamiento...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    }
}

int main() {
    struct fila f;
    inicializar(&f);
    int opcion, valor;

    do {
        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Imprimir\n");
        printf("4. Estacionamiento\n");
        printf("5. Salir\n");
        printf("====================================\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un valor: ");
                scanf("%d", &valor);
                insertar(&f, valor);
                break;
            case 2:
                remover(&f);
                break;
            case 3:
                imprimir(&f);
                break;
            case 4:
                estacionamiento(&f);
                break;
            case 5:
                printf("Fin del programa\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 5);

    return 0;
}