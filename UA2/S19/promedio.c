#include <stdio.h>

//Promedio de una cantidad variable de notas

int main(void){
    //Defino variables
    int cantidad, i;
    double nota, suma, promedio;
    //Inicializo la variable suma
    suma = 0;
    //Pido La cantidad de notas
    printf("¿Cuántas notas va a digitar? ");
    scanf("%d", &cantidad);
    //Iniciamos un ciclo for
    for (i = 1; i <= cantidad; i++)
    {
        //Pedimos notas y las sumamos a suma para acumular
        printf("Nota %d: ", i);
        scanf("%lf", &nota);
        suma += nota;
    }
    //Aqui saco el promedio
    promedio = suma / cantidad;

    //Salida
    printf("Suma: %.2f\n", suma);
    printf("Promedio: %.2f", promedio);
    
}