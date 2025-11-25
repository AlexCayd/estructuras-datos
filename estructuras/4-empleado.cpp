#include <stdio.h>
#include <string.h>
#include <conio.h>

struct registro{
    char nombre[15];
    int id;
    int edad;
    double sal;
};

main()
{
    struct registro emp;
    strcpy(emp.nombre, "JUAN");
    emp.id = 14;
    emp.edad = 22;
    emp.sal =5548.90;
    printf("Nombre empleado y ubicación en memoria: %s %u\n", emp.nombre, &emp.nombre);
    printf("Número empleado y ubicación en memoria: %d %u\n", emp.id, &emp.id);
    printf("Edad empleado y ubicación en memoria: %d %u\n", emp.edad, &emp.edad);
    printf("Salario empleado y ubicación en memoria: %.2lf %u\n", emp.sal, &emp.sal);
    getchar();
}
