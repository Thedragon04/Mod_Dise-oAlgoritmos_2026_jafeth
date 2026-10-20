#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CRITERIOS 3

int main(void){
    //Defino dos arreglos
    char criterios[CRITERIOS][20] = {"puntualidad","calidad","trabajo en equipo"};
    float puntajes[CRITERIOS];
    //Variables a utilizar
    char nombre[50], nivel[50], criterio[20];
    int i, correcto;
    float promedio = 0, menor = 10, actual;

    //Leo el nombre con fgets para leerlo con los espacios
    printf("=== Evaluacion de desempeno ===\n");
    printf("Nombre del colaborador: ");
    fgets(nombre, sizeof(nombre), stdin);

    //For para cada uno de los criterios se lean por separado
    for (i = 0; i < CRITERIOS; i++)
    {
        //Cada que se inicia el for correcto es 0 para que el do while verifique que los puntajes esten correctos
        correcto = 0;
        do
            {
                //Leo los puntajes con i para que pase al siguiente en cada iteracion del for
                printf("Puntaje de %s: ",criterios[i]);
                scanf("%f", &puntajes[i]);
                actual = puntajes[i];
                //Cual es numero menor y su criterio
                if (actual < menor)
                {
                    menor = actual;
                    strcpy(criterio, criterios[i]);
                }
                //Si el puntaje esta correcto cierra el do while y se suma a promedio
                if (puntajes[i] <= 10 && puntajes[i] >= 0)
                {
                    promedio += puntajes[i];
                    correcto = 1;
                }
                else{
                    printf("Puntaje invalido, debe estar 0 y 10\n");
                }


            } while (correcto == 0);
    }

    //Promedio los puntajes y con una estructura if elif else le dijo al que nivel corresponde cada uno
    promedio = promedio / i;
    if (promedio >= 9){
        strcpy(nivel, "EXCELENTE");
    }
    else if (promedio < 9 && promedio >= 7){
        strcpy(nivel, "BUENO");
    }
    else{
        strcpy(nivel, "NECESITA MEJORAR");
    }
    
    //Salida
    printf("\nColaborador: %s",nombre);
    printf("Promedio: %8.2f\n",promedio);
    printf("Nivel: %15s\n",nivel);
    printf("Puntaje mas bajo: %s (%.1f)\n",criterio,menor);

    system("pause");
    return 0;
}