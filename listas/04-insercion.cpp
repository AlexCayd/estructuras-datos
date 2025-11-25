#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *next;
};

void insertar_ordenado(struct Nodo **lista, int x) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (!nuevo) return;
    nuevo->dato = x;
    nuevo->next = NULL;

    struct Nodo *p = *lista;
    struct Nodo *q = NULL;

    while (p != NULL && p->dato < x) {
        q = p;
        p = p->next;
    }

    if (q == NULL) {
        nuevo->next = *lista;
        *lista = nuevo;
    } else {
        nuevo->next = p;
        q->next = nuevo;
    }
}

int eliminar_ordenado(struct Nodo **lista, int x) {
    struct Nodo *p = *lista;
    struct Nodo *q = NULL;

    if (p == NULL) return 0;

    if (p->dato == x) {
        *lista = p->next;
        free(p);
        return 1;
    }

    while (p != NULL && p->dato < x) {
        q = p;
        p = p->next;
    }

    if (p == NULL || p->dato != x) return 0;

    q->next = p->next;
    free(p);
    return 1;
}

void imprimir(const struct Nodo *lista) {
    while (lista) {
        printf("%d ", lista->dato);
        lista = lista->next;
    }
    printf("\n");
}

void liberar_lista(struct Nodo **lista) {
    struct Nodo *p = *lista;
    while (p) {
        struct Nodo *t = p->next;
        free(p);
        p = t;
    }
    *lista = NULL;
}

int main(void) {
    struct Nodo *lista = NULL;

    insertar_ordenado(&lista, 35);
    insertar_ordenado(&lista, 23);
    insertar_ordenado(&lista, 119);
    imprimir(lista);      // 23 35 119

    insertar_ordenado(&lista, 48);
    imprimir(lista);      // 23 35 48 119

    insertar_ordenado(&lista, 5);
    imprimir(lista);      // 5 23 35 48 119

    int valor;
    printf("\nIngresa el valor a eliminar: ");
    if (scanf("%d", &valor) == 1) {
        if (eliminar_ordenado(&lista, valor)) {
            printf("Se elimino %d\n", valor);
        } else {
            printf("No se encontró %d en la lista\n", valor);
        }
        imprimir(lista);
    } else {
        printf("Entrada inválida.\n");
    }

    liberar_lista(&lista);
    return 0;
}
