#include <stdio.h>

void cambio(int *a, int *b) {
    int i;
    i = *a;
    *a = *b;
    *b = i;
} 

int main() {
    int x, y;
    x = 10;
    y = 127;
    cambio(&x, &y);
    printf("\n%d %d\n", x, y);
}