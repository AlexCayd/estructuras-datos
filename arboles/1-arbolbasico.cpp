#include <stdio.h>

struct Nodo {
    int dato;
    struct Nodo* izq;
    struct Nodo* der;
};

struct Arbol {
    struct Nodo* raiz;
};

int main() {
    struct Nodo n1, n2, n3;

    int v1, v2, v3;
    printf("Ingresa tres numeros (ej: 5 3 9): ");
    scanf("%d %d %d", &v1, &v2, &v3);

    n1.dato = v1;
    n1.izq = NULL;
    n1.der = NULL;

    // Colocar el segundo número
    if (v2 < n1.dato) {
        n2.dato = v2;
        n2.izq = NULL;
        n2.der = NULL;
        n1.izq = &n2;   // enlace como hijo izquierdo
    } else {
        n2.dato = v2;
        n2.izq = NULL;
        n2.der = NULL;
        n1.der = &n2;   // enlace como hijo derecho
    }

    // Colocar el tercer número
    if (v3 < n1.dato) {
        n3.dato = v3;
        n3.izq = NULL;
        n3.der = NULL;
        n1.izq = &n3;   // si el izquierdo ya estaba, este lo reemplaza
    } else {
        n3.dato = v3;
        n3.izq = NULL;
        n3.der = NULL;
        n1.der = &n3;   // si el derecho ya estaba, este lo reemplaza
    }

    // Crear árbol y asignar raíz
    struct Arbol miArbol;
    miArbol.raiz = &n1;

    // Imprimir para verificar
    printf("\nRaiz: %d\n", miArbol.raiz->dato);
    if (miArbol.raiz->izq != NULL)
        printf("Izquierdo: %d\n", miArbol.raiz->izq->dato);
    else
        printf("Izquierdo: (vacio)\n");

    if (miArbol.raiz->der != NULL)
        printf("Derecho: %d\n", miArbol.raiz->der->dato);
    else
        printf("Derecho: (vacio)\n");

    return 0;
}
