#include <stdio.h>

int main() {
    int num;
    int *apunt;
    apunt = &num;

    num = 877;
    *apunt+=1;
    printf("%d", num);
}   