#include <stdio.h>

int main() {
    int i, *p;
    i = 43;
    p = &i;
    printf("%d\n", i); // despliega 43
    printf("%d\n", p); // despliega la dirección de la variable i
    printf("%u\n", &i); // despliega la dirección de la variable i, igual que el anterior
    printf("%d\n", *p); // despliega 43, el valor referenciado por la variable p
    printf("%u\n", &p); // despliega la dirección del apuntaodr p

}