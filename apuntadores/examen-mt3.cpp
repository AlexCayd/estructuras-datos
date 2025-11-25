#include <stdio.h>

int main() {
    int num;
    int *apunt;
    apunt = &num;

    num = 880;
    (*apunt)++;
    printf("%d", num);
}   