#include <stdio.h>

int main() {
    //Difino variables
    int fila, columna, n;

    // Pedir la cantidad de filas al usuario
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &n);

    // Ciclo for para los dos patrones
    // Patrón de asteriscos
    printf("\nPatron de asteriscos:\n");
    //Ciclo externo que pasa de fila cada vez que el ciclo interno termina
    for (fila = 1; fila <= n; fila++) 
    {
        //Ciclo interno que imprime un * hasta que columna sea menor o igual al numero de filas actuales. Si fila = 3 entonces columna se repite 3 veces osea 
        //***
        
        for (columna = 1; columna <= fila; columna++) {
            printf("*");
        }
        //Salto de linea para que los asteriscos se acomoden 
        //*
        //**
        //***
        printf("\n");
    }

    // Patrón de números
    printf("\nPatron de numeros: \n");
    for (fila = 1; fila <= n; fila++)
    {
        for (columna = 1; columna <= fila; columna++)
        {
            printf("%d", columna);
        }
        printf("\n");
    }
    

    return 0;
}