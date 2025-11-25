#include <stdio.h>
#include <math.h>

int main() {
    int opcion;
    long num;
    
    printf("Conversor Binario/Decimal\n");
    printf("1. Binario a Decimal\n");
    printf("2. Decimal a Binario\n");
    printf("Elige una opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Binario a Decimal
        printf("\nIngresa un número binario: ");
        scanf("%ld", &num);
        
        long binario = num;
        int decimal = 0, base = 1, resto;
        
        while (num > 0) {
            resto = num % 10;
            decimal += resto * base;
            base *= 2;
            num /= 10;
        }
        
        printf("\nEl número binario %ld en decimal es: %d\n", binario, decimal);
    } 
    else if (opcion == 2) {
        // Decimal a Binario
        printf("\nIngresa un número decimal: ");
        scanf("%ld", &num);
        
        long decimal = num;
        int binario[32], i = 0;
        
        if (num == 0) {
            printf("\nEl número decimal 0 en binario es: 0\n");
            return 0;
        }
        
        while (num > 0) {
            binario[i] = num % 2;
            num /= 2;
            i++;
        }
        
        printf("\nEl número decimal %ld en binario es: ", decimal);
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binario[j]);
        }
        printf("\n");
    } 
    else {
        printf("\nOpción inválida.\n");
    }
    
    return 0;
}
