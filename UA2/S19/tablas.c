//Tablas.c resuelve la tabla del 7

#include <stdio.h>

#define CENTINELA 0

int main(void){
    //Declaracion de variables 
    int numero, i;
    int tablas = 0;

    //lectura previa

    printf("Numero de la tabla(0 para terminar): ");
    scanf("%d",&numero);

    //while con centinela

    while (numero != CENTINELA)
    {
        //For anidado
        for ( i = 1; i <= 10; i++)
        {
            // %2d alinea en 2 espacios
            printf("%d x %2d = %2d\n", numero, i, numero * i);
        }
        tablas++; //cuenta la tabla mostrada
        // siguiente dato al final del conteo -> 3, luego 0
        printf("Numero de la tabla (0 para terminar): ");
        scanf("%d", &numero);
    }
    // despues de while
    printf("Tablas mostradas: %d\n", tablas);
    return 0;
}