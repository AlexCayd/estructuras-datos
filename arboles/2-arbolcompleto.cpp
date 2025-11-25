#include <stdio.h>

// Definir un numero maximo de nodos
#define MAX_NODOS 1000

struct Nodo {
    int dato;
    struct Nodo* izq;
    struct Nodo* der;
};

// Arreglo de nodos
struct Nodo nodos[MAX_NODOS];
int contador_nodos = 0;

struct Nodo* nuevoNodo(int valor) {
    if (contador_nodos >= MAX_NODOS) return NULL; 
    
    struct Nodo* n = &nodos[contador_nodos]; 
    contador_nodos++;
    
    n->dato = valor;
    n->izq = NULL;
    n->der = NULL;
    return n;
}


// Insertar un nuevo nodo en el arbol
struct Nodo* insertar(struct Nodo* raiz, int valor) {
    if (!raiz) return nuevoNodo(valor);
    
    if (valor < raiz->dato) {
        raiz->izq = insertar(raiz->izq, valor);
    } else if (valor > raiz->dato) {
        raiz->der = insertar(raiz->der, valor);
    }
    
    return raiz;
}

void inorden(struct Nodo* raiz) {
    if (raiz) {
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}

void preorden(struct Nodo* raiz) {
    if (raiz) {
        printf("%d ", raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void postorden(struct Nodo* raiz) {
    if (raiz) {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->dato);
    }
}

int buscar(struct Nodo* raiz, int valor) {
    if (!raiz) return 0;
    if (valor == raiz->dato) return 1;
    
    if (valor < raiz->dato) 
        return buscar(raiz->izq, valor);
    else
        return buscar(raiz->der, valor);
}

int minimo(struct Nodo* raiz) {
    while (raiz->izq) {
        raiz = raiz->izq;
    }
    return raiz->dato;
}

int maximo(struct Nodo* raiz) {
    while (raiz->der) {
        raiz = raiz->der;
    }
    return raiz->dato;
}

// Encontrar el padre de un nodo
struct Nodo* encontrarPadre(struct Nodo* raiz, int valor, struct Nodo* padre) {
    if (!raiz) return NULL;
    // Si el dato es igual al valor que se está pidiendo se regresa el padre
    if (raiz->dato == valor) return padre;
    
    struct Nodo* resultado = encontrarPadre(raiz->izq, valor, raiz);
    if (resultado) return resultado;
    
    return encontrarPadre(raiz->der, valor, raiz);
}

// Encontrar un nodo específico
struct Nodo* encontrarNodo(struct Nodo* raiz, int valor) {
    if (!raiz) return NULL;
    if (raiz->dato == valor) return raiz;
    
    struct Nodo* resultado = encontrarNodo(raiz->izq, valor);
    if (resultado) return resultado;
    
    return encontrarNodo(raiz->der, valor);
}

// Encontrar el hermano de un nodo (si tiene)
struct Nodo* encontrarHermano(struct Nodo* raiz, int valor) {
    struct Nodo* padre = encontrarPadre(raiz, valor, NULL);
    if (!padre) return NULL; // No tiene padre (es raíz)
    
    // Si el nodo está a la izquierda del padre, el hermano está a la derecha
    if (padre->izq && padre->izq->dato == valor) {
        return padre->der;
    }
    // Si el nodo está a la derecha del padre, el hermano está a la izquierda
    else if (padre->der && padre->der->dato == valor) {
        return padre->izq;
    }
    
    return NULL;
}

// Mostrar las relaciones de un nodo
void mostrarRelaciones(struct Nodo* raiz, int valor) {
    // Verificar si el nodo existe
    if (!buscar(raiz, valor)) {
        printf("\n%d NO esta en el arbol\n", valor);
        return;
    }
    
    printf("\nRelaciones del nodo %d\n", valor);
    
    // Encontrar el nodo
    struct Nodo* nodo = encontrarNodo(raiz, valor);
    // Padre
    struct Nodo* padre = encontrarPadre(raiz, valor, NULL);
    if (padre) {
        printf("Padre: %d\n", padre->dato);
    } else {
        printf("Padre: (ninguno, es la raiz)\n");
    }
    
    // Hijo izquierdo
    if (nodo->izq) {
        printf("Hijo izquierdo: %d\n", nodo->izq->dato);
    } else {
        printf("Hijo izquierdo: no tiene\n");
    }
    
    // Hijo derecho
    if (nodo->der) {
        printf("Hijo derecho: %d\n", nodo->der->dato);
    } else {
        printf("Hijo derecho: no tiene\n");
    }
    
    // Hermano
    struct Nodo* hermano = encontrarHermano(raiz, valor);
    if (hermano) {
        printf("Hermano: %d\n", hermano->dato);
    } else {
        printf("Hermano: (ninguno)\n");
    }
}

int main() {
    struct Nodo* arbol = NULL;
    int n, valor, busqueda;
    
    printf("Cuantos numeros quieres insertar? ");
    scanf("%d", &n);
    
    printf("Ingresa %d numeros: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        arbol = insertar(arbol, valor);
    }
    
    printf("\nRecorrido Inorden (izq-raiz-der): ");
    inorden(arbol);
    printf("\n");
    
    printf("Recorrido Preorden (raiz-izq-der): ");
    preorden(arbol);
    printf("\n");
    
    printf("Recorrido Postorden (izq-der-raiz): ");
    postorden(arbol);
    printf("\n");
    
    if (arbol) {
        printf("\nMinimo: %d\n", minimo(arbol));
        printf("Maximo: %d\n", maximo(arbol));
        printf("Diferencia (max-min): %d\n", maximo(arbol) - minimo(arbol));
    } else {
        printf("El arbol está vacío\n");
    }
    
    printf("\nQue numero quieres buscar? ");
    scanf("%d", &busqueda);
    
    mostrarRelaciones(arbol, busqueda);
    
    return 0;
}