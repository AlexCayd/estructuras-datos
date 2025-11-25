#include <stdio.h>

struct nodo {
    int info;
    struct nodo *sig;
};

int main() {
    struct nodo *nuevo;
    nuevo = new(nodo);

    nuevo -> info = 25;
    printf("El dato en el nodo es: %d\n", nuevo->info);
}