#include <stdio.h>

int main() {
    int i, *p;
    i = 43;
    printf("\n%d\n", i);
    p = &i; // p está inicializado en la dirección de i
    *p = 16;
    printf("%d\n", i);
}