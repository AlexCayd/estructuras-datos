#include <stdio.h>

int main() {
    int num;
    int *apunt;
    apunt = &num;

    num = 879;
    *(apunt++);
    printf("%d", num);
}   