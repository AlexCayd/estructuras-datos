#include <stdio.h>

struct nodo {
    int info;
    nodo *sig;
};

int main() {
    nodo *ap_uno, *ap_dos, *ap_tres;

    ap_uno = new nodo;
    ap_dos = new nodo;
    ap_tres = new nodo;

    ap_uno->info = 45;
    ap_dos->info = 56;
    ap_tres->info = 12;

    ap_uno->sig = ap_dos;
    ap_dos->sig = ap_tres;
    ap_tres->sig = nullptr; 

    nodo *actual = ap_uno;
    while (actual != nullptr) {
        printf("Dato: %d\n", actual->info);
        actual = actual->sig;
    }

    return 0;
}
