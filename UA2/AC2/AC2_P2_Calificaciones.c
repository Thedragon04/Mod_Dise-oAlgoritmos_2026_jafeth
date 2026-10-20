/*Un centro educativo necesita automatizar el cálculo de notas finales. Escriba un programa en C
que:
1. Reciba el nombre completo del estudiante.
2. Reciba tres calificaciones de 0 a 100 y las guarde en un arreglo. Cada calificación fuera de rango se rechaza con un mensaje y se vuelve a pedir.
3. Calcule el promedio de las tres calificaciones y busque la calificación más alta recorriendo el arreglo.
4. Determine la condición: APROBADO si el promedio es 70 o más; EN RIESGO si es 60 o más, pero menor que 70; NO APROBADO si es menor que 60. Guarde la condición en una cadena.
5. Muestre el nombre, las tres calificaciones, el promedio (dos decimales), la calificación más alta y la condición.
Requisitos en C
Use un arreglo float notas[3] recorrido con for, un do … while para validar cada nota, constantes
para los límites y strcpy para guardar la condición.
Al inicio del archivo escriba en comentarios el enunciado, qué se logra,*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CALIFICACIONES 3

int main(void){
    //arreglo para guardar las calificacion
    float calificacion[CALIFICACIONES];
    //variables
    float promedio, mas_alta = 0;
    char nombre[50], condicion[12];
    int i;

    //Pedimos el nombre sin validar si es vacio
    printf("=== Calificaciones del estudiante === \n");
    printf("Nombre del estudiante: ");
    fgets(nombre, sizeof(nombre),stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    //Ciclo for para las 3 calificaciones
    for (i = 0; i < CALIFICACIONES; i++)
    {
        //Ciclo para validar la nota no sea menor a 0 ni mayor a 100
        do
        {
            printf("Calificacion %d (0 a 100): ", i+1);
            scanf("%f", &calificacion[i]);
            if (calificacion[i] < 0 || calificacion[i] > 100)
            {
                printf("Rango invalido, de 0 a 100\n");
            }
            
        } while (calificacion[i] < 0 || calificacion[i] > 100);
        //Comparo las nota actual con que esta guardada la primera vez es un 0
        if (calificacion[i] > mas_alta)
        {
            //Si se cumple la nota mas alta pasa a ser la actual
            mas_alta = calificacion[i];
        }
        //Sumo nota actual a promedio
        promedio += calificacion[i];
        
    }

    
    promedio = promedio / CALIFICACIONES;
    //Condicion si esta aprobado con el promedio
    if (promedio >= 70)
    {
        strcpy(condicion, "APROBADO");
    }
    else if (promedio < 70 && promedio >= 60)
    {
        strcpy(condicion, "EN RIESGO");
    }
    else{strcpy(condicion, "NO APROBADO");}
    
    

    //Salidas
    printf("\n------- Resultado -------\n");
    printf("Estudiante: %s\n",nombre);
    for (i = 0; i < CALIFICACIONES; i++)
    {
        printf("Calificacion %d:    %.1f\n", i+1,calificacion[i]);
    }
    printf("Promedio: %13.2f\n",promedio);
    printf("Nota mas alta: %8.1f\n",mas_alta);
    printf("Condicion: %16s\n",condicion);
    system("pause");
    return 0;
}