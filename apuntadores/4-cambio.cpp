#include <stdio.h>

void cambio(int *apunt) {
    *apunt = 351;
}

int main() {
    int x;
    x = 146;
    cambio(&x);
    printf("\n%d\n", x);
}