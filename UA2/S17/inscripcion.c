#include <stdio.h>
#define COSTO_MODULO 15000.0;

int main(void){
    //Cadenas: arreglos de caracteres
    char nombre[30];
    char cedula[15];
    int cantidadModulos;
    double total;
    // Logico
    int tieneDescuento;

    //ENTRADAS
    //Pide y almacena nombre. en el tipo char no se usa & para almacenar con scanf
    printf("Nombre: ");
    scanf("%29s", nombre);

    //leer cedula
    printf("Cedula: ");
    scanf("%14s", cedula);

    //pedir y almacenar cantidad de modulos
    printf("Cantidad de modulo: ");
    scanf("%d", cantidadModulos);

    //Procesos total = 3 * 15000 -> 45000
    total = cantidadModulos * COSTO_MODULO;
    //A la pregunta tiene descuento se responde con un 1 para si y 0 para no
    tieneDescuento = cantidadModulos >= 3;

    //Salidas
    printf("Estudiante: %s (%s)\n", nombre, cedula);
    printf("Total de la inscripcion: %.2f\n", total);
    printf("¿Aplica para descuento? %d (1 = si, 0 = no)\n", tieneDescuento);

    return 0;

}