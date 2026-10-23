// Convertir numero decimal de 0 a 15 a binario bits
#include <stdio.h>

int main(void){ //No recibe ningun parametro o argumento del sistema
    int numero;// declarion de variables de tipo entero
    int cociente;
    int b0,b1,b2,b3;//un bit(Residuo) Por cada division

    //ENTRADA: Lee el numero -> numero = 13

    printf("Numero decimal (0 a 15):");
    scanf("%d", &numero);

    //VALIDACION: con 4 bits solo se representa los valores de 0 a 15
    if (numero < 0 || numero > 15){
        printf("Fuera de rango: use un numero de 0 a 15");
        return 1; //Termina indicando que hubo un error

    }

    //Se empieza dividiendo el numero completo -> cociente = 13
    cociente = numero;
    // division entre 1: el residuo es el bit de las unidades -> b0 = 1
    b0 = cociente % 2;

    //Muestra el paso de 13 / 2 = 6 residuo es 1
    printf("%d / 2 = %d residuo %d\n", cociente, cociente /2 , b0);

    cociente = cociente / 2;
    //El cociente pasa a la division = 6
    b1 = cociente % 2;

    //Muestra el paso de 6 / 2 = 3 residuo es 0
    printf("%2d / 2 = %d residuo %d\n", cociente, cociente /2  , b1);

    cociente = cociente / 2;
    //El cociente pasa a la division = 3
    b2 = cociente % 2;

    //Muestra el paso de 3 / 2 = 1 residuo es 1
    printf("%2d / 2 = %d residuo %d\n", cociente,cociente /2  , b2);

    cociente = cociente / 2;
    //El cociente pasa a la division = 1
    b3 = cociente % 2;

    //Muestra el paso de 1 / 2 = 0 residuo es 1
    printf("%2d / 2 = %d residuo %d\n", cociente,cociente /2, b3);

    //RESULTADO: Los residuos se leen de abajo hacia arriba -> 1101

    printf("En binario %d%d%d%d\n", b3, b2, b1, b0);

    //COMPROBACIÓN: %o muestra en octal y %x en hexadecimal <> 15 y D
    printf("Comprobacion: octal %o, hexadecimal %X\n", numero, numero);

    return 0;
}