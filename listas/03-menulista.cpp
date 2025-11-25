#include <stdio.h>

#define MAX_NODOS 100

struct Nodo {
    int dato;
    int sig;
};

struct Nodo lista[MAX_NODOS];
int cabeza = -1;    
int libre  = 0;     

void inicializarLista() {
    for (int i = 0; i < MAX_NODOS - 1; i++) {
        lista[i].sig = i + 1; 
    }
    lista[MAX_NODOS - 1].sig = -1;
    cabeza = -1;
    libre  = 0;
}

int nuevoNodo(int valor) {
    if (libre == -1) {
        printf("No hay espacio disponible.\n");
        return -1;
    }
    int indice = libre;
    libre = lista[libre].sig;
    lista[indice].dato = valor;
    lista[indice].sig  = -1;
    return indice;
}

void liberarNodo(int indice) {
    lista[indice].sig = libre;
    libre = indice;
}

void insertarFinal(int valor) {
    int indice = nuevoNodo(valor);
    if (indice == -1) return;

    if (cabeza == -1) {
        cabeza = indice;
    } else {
        int temp = cabeza;
        while (lista[temp].sig != -1) temp = lista[temp].sig;
        lista[temp].sig = indice;
    }
}

void eliminarNodo(int valor) {
    int temp = cabeza, anterior = -1;

    while (temp != -1 && lista[temp].dato != valor) {
        anterior = temp;
        temp = lista[temp].sig;
    }

    if (temp == -1) {
        printf("El valor %d no esta en la lista.\n", valor);
        return;
    }

    if (anterior == -1) cabeza = lista[temp].sig;
    else lista[anterior].sig = lista[temp].sig;

    liberarNodo(temp);
    printf("Nodo con valor %d eliminado.\n", valor);
}

void imprimirLista() {
    if (cabeza == -1) {
        printf("La lista esta vacia.\n");
        return;
    }
    printf("Lista: ");
    int temp = cabeza;
    while (temp != -1) {
        printf("%d -> ", lista[temp].dato);
        temp = lista[temp].sig;
    }
    printf("NULL\n");
}

void insertarOrden(int valor) {
    int indice = nuevoNodo(valor);
    if (indice == -1) return;

    if (cabeza == -1 || valor < lista[cabeza].dato) {
        lista[indice].sig = cabeza;
        cabeza = indice;
    } else {
        int temp = cabeza;
        while (lista[temp].sig != -1 && lista[lista[temp].sig].dato < valor)
            temp = lista[temp].sig;

        lista[indice].sig = lista[temp].sig;
        lista[temp].sig   = indice;
    }
}

int digitoEn(int x, int k) {
    for (int i = 0; i < k; i++) x /= 10;
    return x % 10;
}

int maxDatoLista() {
    if (cabeza == -1) return 0;
    int m = lista[cabeza].dato;
    for (int i = lista[cabeza].sig; i != -1; i = lista[i].sig)
        if (lista[i].dato > m) m = lista[i].dato;
    return m;
}

int minDatoLista() {
    if (cabeza == -1) return 0;
    int m = lista[cabeza].dato;
    for (int i = lista[cabeza].sig; i != -1; i = lista[i].sig)
        if (lista[i].dato < m) m = lista[i].dato;
    return m;
}

int obtenerRango() {
    if (cabeza == -1) return 0;
    int minDato, maxDato, rango;
    minDato = minDatoLista();
    maxDato = maxDatoLista();
    rango = maxDato - minDato;
    return rango;
}   

int numDigitos(int x) {
    int d = 1;
    while (x >= 10) { x /= 10; d++; }
    return d;
}

void radixSortLista() {
    if (cabeza == -1 || lista[cabeza].sig == -1) return; 

    int maxVal = maxDatoLista();
    int pases  = numDigitos(maxVal);

    for (int k = 0; k < pases; k++) {
        int head[10], tail[10];
        for (int b = 0; b < 10; b++) head[b] = tail[b] = -1;

        for (int i = cabeza; i != -1; ) {
            int nxt = lista[i].sig;  
            lista[i].sig = -1;       

            int d = digitoEn(lista[i].dato, k);
            if (head[d] == -1) {
                head[d] = tail[d] = i;
            } else {
                lista[tail[d]].sig = i;
                tail[d] = i;
            }
            i = nxt;
        }

        int nuevaCabeza = -1, nuevaCola = -1;
        for (int b = 0; b < 10; b++) {
            if (head[b] == -1) continue;
            if (nuevaCabeza == -1) {
                nuevaCabeza = head[b];
                nuevaCola   = tail[b];
            } else {
                lista[nuevaCola].sig = head[b];
                nuevaCola = tail[b];
            }
        }
        cabeza = nuevaCabeza;
    }
    printf("Lista ordenada con Radix (LSD, base 10).\n");
}

int main() {
    int opcion, valor, rango;
    inicializarLista();

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Insertar al final\n");
        printf("2. Eliminar cualquier nodo\n");
        printf("3. Imprimir lista\n");
        printf("4. Insertar en orden\n");
        printf("5. Ordenar con Radix (LSD)\n");
        printf("6. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Valor a insertar al final: ");
                scanf("%d", &valor);
                insertarFinal(valor);
                rango = obtenerRango();
                printf("El rango entre el mayor y el menor es: %d\n", rango);
                break;
            case 2:
                printf("Valor a eliminar: ");
                scanf("%d", &valor);
                eliminarNodo(valor);
                break;
            case 3:
                imprimirLista();
                break;
            case 4:
                printf("Valor a insertar en orden: ");
                scanf("%d", &valor);
                insertarOrden(valor);
                break;
            case 5:
                radixSortLista();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 6);

    return 0;
}