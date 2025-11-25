#include <stdio.h>

int main() {
    int num;
    int *apunt;
    apunt = &num;

    num = 869;
    *apunt++;
    printf("%d", num);
}   