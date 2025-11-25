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
    struct registro *p;

    p = &emp;

    strcpy(p->nombre, "JUAN");
    p->id = 14;
    p->edad = 22;
    p->sal =5548.90;
    printf("Nombre empleado y ubicación en memoria: %s %u\n", p->nombre, &emp.nombre);
    printf("Número empleado y ubicación en memoria: %d %u\n", p->id, &emp.id);
    printf("Edad empleado y ubicación en memoria: %d %u\n", p->edad, &emp.edad);
    printf("Salario empleado y ubicación en memoria: %.2lf %u\n", p->id, &emp.sal);
    getchar();
}
