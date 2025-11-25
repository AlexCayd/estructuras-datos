#include <stdio.h>

int main() {
    int num = 2;

    while(num <= 1800) {
        printf("\n Numero: %d", num);
        num = num + 3;
        printf("\n Numero: %d", num);
        num = num + 2;
    }
}