#include <stdio.h>
#include <string.h>

struct pila {
    int top;
    int elementos[100];
};

void push(struct pila *ps, int x) {
    if (ps->top == 99) {
        printf("Overflow\n");
        return;
    }

    ps->top++;
    ps->elementos[ps->top] = x;

    printf("Nuevo valor de top: %d\n", ps->top);
    printf("Elemento insertado: %d\n", x);
}

void pop (struct pila *ps) {
    if (ps->top < 0) {
        printf("Underflow\n");
        return;
    }
    
    int elemento = ps->elementos[ps->top];
    printf("Elemento eliminado: %d\n", elemento);

    ps->top--;

    printf("Nuevo valor de top: %d\n", ps->top);
}

void imprimir(struct pila *ps) {
    printf("Pila: \n");
    for (int i = 0; i <= ps->top; i++) {
        printf("%d\n", ps->elementos[i]);
    }
}

int empareja(char open, char close) {
    return (open=='(' && close==')') ||
           (open=='[' && close==']') ||
           (open=='{' && close=='}');
}

void balanceo() {
    struct pila balance;
    char expresion[100];

    balance.top = -1;

    printf("Ingresa la expresion para balancear: ");
    scanf("%99s", expresion);
    printf("Expresion ingresada: %s\n", expresion);

    if (expresion[0] == '}' || expresion[0] == ']' || expresion[0] == ')') {
        printf("No balanceada: hay un cierre al principio.\n");
        return;
    }

    for (int i = 0; i < (int)strlen(expresion); i++) {
        char c = expresion[i];

        if (c=='{' || c=='(' || c=='[') {
            push(&balance, c);
        } else if (c=='}' || c==')' || c==']') {
            if (balance.top < 0) {
                printf("No balanceada: cierre '%c' sin apertura en pos %d.\n", c, i);
                return;
            }
            char anterior = (char)balance.elementos[balance.top];
            balance.top--;

            if (!empareja(anterior, c)) {
                printf("No balanceada: se cerro '%c' con '%c' en pos %d.\n", anterior, c, i);
                return;
            }
        }
    }

    if (balance.top == -1) {
        printf("Balanceada\n");
    } else {
        printf("No balanceada: quedaron aperturas sin cerrar.\n");
    }
}

int main() {
    int menu;
    struct pila s;
    s.top = -1;
    
    do {
        printf("\nSelecciona una opcion del menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Imprimir\n");
        printf("4. Balanceo\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: {
                int valor;
                printf("Push: Ingresa el elemento a insertar\n");
                scanf("%d", &valor);
                push(&s, valor);
                break;
            }
            case 2:
                pop(&s);
                break;
            case 3:
                imprimir(&s);
                break;
            case 4:
                balanceo();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Prueba de nuevo\n\n");
                break;
        }
    } while (menu != 5);

    return 0;
}
