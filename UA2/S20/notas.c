//notas.c la trabajamos como un arreglo. Ahora la se guardan
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(void){
    double notas[N]; // Definicion del arreglo
    double suma = 0, promedio, mayor, menor;
    int i;

    //lectura de datos
    for (i = 0; i < N; i++)
    //Validacion
    {
        do
        {
            printf("Nota %d (0 a 100): ", i + 1);
            scanf("%lf", &notas[i]);//Guarda en notas[i]

        } while (notas[i] < 0 || notas[i] > 100);
        suma += notas[i];
        
    }
    promedio = suma / N;

    //Mayor y menor
    mayor = notas[0];
    menor = notas[0];

    for (i = 1; i < N; i++)
    {
        if (notas[i] > mayor)
        {
            mayor = notas[i];
        }
        
        if (notas[i] < menor)
        {
            menor = notas[i];
        }
    }

    printf("Promedio: %.2f\n", promedio);
    printf("Mayor: %.1f Menor: %.1f\n", mayor,menor);


    //Segundo recorrido
    printf("Sobre el promedio: ");
    for (i = 0; i < N; i++)
    {
        if (notas[i] > promedio)
        {
            printf(" %.1f",notas);
        }
        
    }
    printf("\n");
    system("pause");
    

    
    return 0;

}