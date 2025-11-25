#include <stdio.h>

void cambio(int *apunt) {
    *apunt = 351;
} 

int main() {
    int x;
    int *p;
    p = &x;
    x = 146;
    cambio(p);
    printf("%d\n", x);
}
